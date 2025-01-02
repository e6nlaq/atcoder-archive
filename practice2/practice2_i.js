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

// node_modules/ac-library-js/dist/internal_types.js
var require_internal_types = __commonJS({
  "node_modules/ac-library-js/dist/internal_types.js"(exports2) {
    "use strict";
    Object.defineProperty(exports2, "__esModule", { value: true });
    exports2.to_array = to_array;
    var types_1 = require("node:util/types");
    function to_array(v) {
      if (Array.isArray(v)) {
        return v;
      }
      if ((0, types_1.isBigInt64Array)(v) || (0, types_1.isBigUint64Array)(v)) {
        return [...v];
      }
      return [...v];
    }
  }
});

// node_modules/ac-library-js/dist/string.js
var require_string = __commonJS({
  "node_modules/ac-library-js/dist/string.js"(exports2) {
    "use strict";
    Object.defineProperty(exports2, "__esModule", { value: true });
    exports2.internal = void 0;
    exports2.suffix_array = suffix_array2;
    exports2.lcp_array = lcp_array2;
    exports2.z_algorithm = z_algorithm;
    var types_1 = require("node:util/types");
    var internal_types_1 = require_internal_types();
    var internal;
    (function(internal2) {
      function sa_naive(s) {
        const n = s.length;
        const sa = Int32Array.from({ length: n }, (_, i) => i);
        sa.sort((l, r) => {
          if (l === r)
            return 0;
          while (l < n && r < n) {
            if (s[l] !== s[r])
              return s[l] - s[r];
            l++;
            r++;
          }
          return l === n ? -1 : 1;
        });
        return sa;
      }
      internal2.sa_naive = sa_naive;
      function sa_doubling(s) {
        const n = s.length;
        const sa = Int32Array.from({ length: n }, (_, i) => i);
        let rnk = new Int32Array(n);
        rnk.set(s);
        let tmp = new Int32Array(n);
        for (let k = 1; k < n; k *= 2) {
          const cmp = (x, y) => {
            if (rnk[x] !== rnk[y])
              return rnk[x] - rnk[y];
            const rx = x + k < n ? rnk[x + k] : -1;
            const ry = y + k < n ? rnk[y + k] : -1;
            return rx - ry;
          };
          sa.sort(cmp);
          tmp[sa[0]] = 0;
          for (let i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) < 0 ? 1 : 0);
          }
          [rnk, tmp] = [tmp, rnk];
        }
        return sa;
      }
      internal2.sa_doubling = sa_doubling;
      function sa_is(s, upper, THRESHOLD_NAIVE = 10, THRESHOLD_DOUBLING = 40) {
        const n = s.length;
        if (n === 0)
          return new Int32Array();
        if (n === 1)
          return new Int32Array([0]);
        if (n === 2) {
          if (s[0] < s[1]) {
            return new Int32Array([0, 1]);
          }
          return new Int32Array([1, 0]);
        }
        if (n < THRESHOLD_NAIVE) {
          return sa_naive(s);
        }
        if (n < THRESHOLD_DOUBLING) {
          return sa_doubling(s);
        }
        const sa = new Int32Array(n);
        const ls = new Array(n).fill(false);
        for (let i = n - 2; i >= 0; i--) {
          ls[i] = s[i] === s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];
        }
        const sum_l = new Int32Array(upper + 1);
        const sum_s = new Int32Array(upper + 1);
        for (let i = 0; i < n; i++) {
          if (!ls[i]) {
            sum_s[s[i]]++;
          } else {
            sum_l[s[i] + 1]++;
          }
        }
        for (let i = 0; i <= upper; i++) {
          sum_s[i] += sum_l[i];
          if (i < upper)
            sum_l[i + 1] += sum_s[i];
        }
        const induce = (lms2) => {
          sa.fill(-1);
          const buf = new Int32Array(upper + 1);
          buf.set(sum_s);
          for (const d of lms2) {
            if (d === n)
              continue;
            sa[buf[s[d]]++] = d;
          }
          buf.set(sum_l);
          sa[buf[s[n - 1]]++] = n - 1;
          for (let i = 0; i < n; i++) {
            const v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
              sa[buf[s[v - 1]]++] = v - 1;
            }
          }
          buf.set(sum_l);
          for (let i = n - 1; i >= 0; i--) {
            const v = sa[i];
            if (v >= 1 && ls[v - 1]) {
              sa[--buf[s[v - 1] + 1]] = v - 1;
            }
          }
        };
        const lms_map = new Int32Array(n + 1).fill(-1);
        let m = 0;
        for (let i = 1; i < n; i++) {
          if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
          }
        }
        const lms = new Array();
        for (let i = 1; i < n; i++) {
          if (!ls[i - 1] && ls[i]) {
            lms.push(i);
          }
        }
        induce(new Int32Array(lms));
        if (m) {
          const sorted_lms = new Array();
          for (const v of sa) {
            if (lms_map[v] !== -1)
              sorted_lms.push(v);
          }
          const rec_s = new Int32Array(m);
          let rec_upper = 0;
          rec_s[lms_map[sorted_lms[0]]] = 0;
          for (let i = 1; i < m; i++) {
            let l = sorted_lms[i - 1];
            let r = sorted_lms[i];
            const end_l = lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n;
            const end_r = lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n;
            let same = true;
            if (end_l - l !== end_r - r) {
              same = false;
            } else {
              while (l < end_l) {
                if (s[l] !== s[r]) {
                  break;
                }
                l++;
                r++;
              }
              if (l === n || s[l] !== s[r])
                same = false;
            }
            if (!same)
              rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
          }
          const rec_sa = sa_is(rec_s, rec_upper, THRESHOLD_NAIVE, THRESHOLD_DOUBLING);
          for (let i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
          }
          induce(new Int32Array(sorted_lms));
        }
        return sa;
      }
      internal2.sa_is = sa_is;
    })(internal || (exports2.internal = internal = {}));
    function suffix_array2(s, upper) {
      if (upper !== void 0) {
        if (!(0, types_1.isInt32Array)(s)) {
          s = new Int32Array(s);
        }
        if (upper < 0) {
          throw new RangeError("upper must be 0<=upper");
        }
        for (const d of s) {
          if (!(0 <= d && d <= upper)) {
            throw new RangeError("s[i] must be 0<=s[i]<=upper");
          }
        }
        const sa = internal.sa_is(s, upper);
        return sa;
      }
      if (typeof s === "string") {
        const n2 = s.length;
        const s22 = new Int32Array(n2);
        for (let i = 0; i < n2; i++) {
          s22[i] = s.charCodeAt(i);
        }
        return internal.sa_is(s22, 255);
      }
      s = (0, internal_types_1.to_array)(s);
      const n = s.length;
      const idx = Int32Array.from({ length: n }, (_, i) => i);
      idx.sort((l, r) => s[l] < s[r] ? -1 : s[l] === s[r] ? 0 : 1);
      const s2 = new Int32Array(n);
      let now = 0;
      for (let i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] !== s[idx[i]])
          now++;
        s2[idx[i]] = now;
      }
      return internal.sa_is(s2, now);
    }
    function lcp_array2(s, sa) {
      if (!(0, types_1.isInt32Array)(sa)) {
        sa = new Int32Array(sa);
      }
      if (typeof s === "string") {
        const n2 = s.length;
        const s2 = new Array(n2);
        for (let i = 0; i < n2; i++) {
          s2[i] = s.charCodeAt(i);
        }
        return lcp_array2(s2, sa);
      }
      s = (0, internal_types_1.to_array)(s);
      const n = s.length;
      if (n < 1) {
        throw new RangeError("n must be 1<=n");
      }
      const rnk = new Int32Array(n);
      for (let i = 0; i < n; i++) {
        rnk[sa[i]] = i;
      }
      const lcp = new Int32Array(n - 1);
      let h = 0;
      for (let i = 0; i < n; i++) {
        if (h > 0)
          h--;
        if (rnk[i] === 0)
          continue;
        const j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
          if (s[j + h] !== s[i + h])
            break;
        }
        lcp[rnk[i] - 1] = h;
      }
      return lcp;
    }
    function z_algorithm(s) {
      if (typeof s === "string") {
        const n2 = s.length;
        const s2 = new Array(n2);
        for (let i = 0; i < n2; i++) {
          s2[i] = s.charCodeAt(i);
        }
        return z_algorithm(s2);
      }
      s = (0, internal_types_1.to_array)(s);
      const n = s.length;
      if (n === 0)
        return new Int32Array();
      const z = new Int32Array(n);
      z[0] = 0;
      for (let i = 1, j = 0; i < n; i++) {
        z[i] = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
        while (i + z[i] < n && s[z[i]] === s[i + z[i]])
          z[i]++;
        if (j + z[j] < i + z[i])
          j = i;
      }
      z[0] = n;
      return z;
    }
  }
});

// main.ts
var import_string = __toESM(require_string());
var import_node_fs = require("node:fs");
function main(inp) {
  const S = inp[0][0];
  const N = S.length;
  const sa = (0, import_string.suffix_array)(S);
  const lcp = (0, import_string.lcp_array)(S, sa);
  console.log(N * (N + 1) / 2 - lcp.reduce((s, v) => s + v));
}
main(
  (0, import_node_fs.readFileSync)("/dev/stdin", "utf-8").split("\n").map((line) => line.split(" "))
);
