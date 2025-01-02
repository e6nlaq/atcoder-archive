"use strict";
var __create = Object.create;
var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __getProtoOf = Object.getPrototypeOf;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __commonJS = (cb, mod) => function __require() {
  return mod || (0, cb[__getOwnPropNames(cb)[0]])((mod = { exports: {} }).exports, mod), mod.exports;
};
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toESM = (mod, isNodeMode, target) => (target = mod != null ? __create(__getProtoOf(mod)) : {}, __copyProps(
  // If the importer is in node compatibility mode or this is not an ESM
  // file that has been converted to a CommonJS file using a Babel-
  // compatible transform (i.e. "__esModule" has not been set), then set
  // "default" to the CommonJS "module.exports" for node compatibility.
  isNodeMode || !mod || !mod.__esModule ? __defProp(target, "default", { value: mod, enumerable: true }) : target,
  mod
));

// node_modules/ac-library-js/dist/internal_csr.js
var require_internal_csr = __commonJS({
  "node_modules/ac-library-js/dist/internal_csr.js"(exports2) {
    "use strict";
    Object.defineProperty(exports2, "__esModule", { value: true });
    exports2.CSR = void 0;
    var CSR = class {
      start;
      elist;
      constructor(n, edges) {
        this.start = new Int32Array(n + 1);
        this.elist = new Array(edges.length);
        for (const [v, _] of edges) {
          this.start[v + 1]++;
        }
        for (let i = 1; i <= n; i++) {
          this.start[i] += this.start[i - 1];
        }
        const counter = this.start.slice();
        for (const [v, e] of edges) {
          this.elist[counter[v]++] = e;
        }
      }
    };
    exports2.CSR = CSR;
  }
});

// node_modules/ac-library-js/dist/internal_scc.js
var require_internal_scc = __commonJS({
  "node_modules/ac-library-js/dist/internal_scc.js"(exports2) {
    "use strict";
    Object.defineProperty(exports2, "__esModule", { value: true });
    exports2.InternalSCCGraph = void 0;
    var internal_csr_1 = require_internal_csr();
    var InternalSCCGraph = class {
      _n;
      edges;
      constructor(n) {
        this._n = n;
        this.edges = [];
      }
      num_vertices() {
        return this._n;
      }
      add_edge(from, to) {
        this.edges.push([from, { to }]);
      }
      // Returns [number of SCCs, SCC ids]
      scc_ids() {
        const g = new internal_csr_1.CSR(this._n, this.edges);
        let now_ord = 0;
        let group_num = 0;
        const visited = [];
        const low = new Int32Array(this._n);
        const ord = new Int32Array(this._n).fill(-1);
        const ids = new Int32Array(this._n);
        const dfs = (v) => {
          low[v] = ord[v] = now_ord++;
          visited.push(v);
          for (let i = g.start[v]; i < g.start[v + 1]; i++) {
            const to = g.elist[i].to;
            if (ord[to] === -1) {
              dfs(to);
              low[v] = Math.min(low[v], low[to]);
            } else {
              low[v] = Math.min(low[v], ord[to]);
            }
          }
          if (low[v] === ord[v]) {
            while (true) {
              const u = visited[visited.length - 1];
              visited.pop();
              ord[u] = this._n;
              ids[u] = group_num;
              if (u === v)
                break;
            }
            group_num++;
          }
        };
        for (let i = 0; i < this._n; i++) {
          if (ord[i] === -1)
            dfs(i);
        }
        for (let i = 0; i < this._n; i++) {
          ids[i] = group_num - 1 - ids[i];
        }
        return [group_num, ids];
      }
      scc() {
        const [group_num, ids] = this.scc_ids();
        const counts = new Int32Array(group_num);
        for (const id of ids) {
          counts[id]++;
        }
        const groups = new Array(group_num).fill([]).map(() => []);
        for (let i = 0; i < this._n; i++) {
          groups[ids[i]].push(i);
        }
        return groups;
      }
    };
    exports2.InternalSCCGraph = InternalSCCGraph;
  }
});

// node_modules/ac-library-js/dist/scc.js
var require_scc = __commonJS({
  "node_modules/ac-library-js/dist/scc.js"(exports2) {
    "use strict";
    Object.defineProperty(exports2, "__esModule", { value: true });
    exports2.SCCGraph = void 0;
    var internal_scc_1 = require_internal_scc();
    var SCCGraph2 = class {
      internal;
      constructor(n = 0) {
        this.internal = new internal_scc_1.InternalSCCGraph(n);
      }
      add_edge(from, to) {
        const n = this.internal.num_vertices();
        if (!(0 <= from && from < n && 0 <= to && to < n)) {
          throw new RangeError("Out of range");
        }
        this.internal.add_edge(from, to);
      }
      scc() {
        return this.internal.scc();
      }
    };
    exports2.SCCGraph = SCCGraph2;
  }
});

// main.ts
var import_scc = __toESM(require_scc());
var import_node_fs = require("node:fs");
function main(inp) {
  const [N, M] = inp[0].map(Number);
  const G = new import_scc.SCCGraph(N);
  for (let i = 1; i <= M; i++) {
    const [a, b] = inp[i].map(Number);
    G.add_edge(a, b);
  }
  const ans = G.scc();
  console.log(ans.length);
  for (let i = 0; i < ans.length; i++) console.log(`${ans[i].length} ${ans[i].join(" ")}`);
}
main(
  (0, import_node_fs.readFileSync)("/dev/stdin", "utf-8").split("\n").map((line) => line.split(" "))
);
