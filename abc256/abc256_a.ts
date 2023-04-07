
function main(input) {
    const args = input.split('\n');

    const N: number = parseInt(args[0]);

    console.log(2 ** N);

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
