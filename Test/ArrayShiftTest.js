var N = 223781;
var a_pop = [];
var a_shift = [];
function main() {
    for(var i = 0; i < N; i++) {
        a_pop.push(i);
    }
    for(var i = 0; i < N; i++) {
        a_shift.push(i);
    }

    start = Date.now();
    for(var i = 0; i < N; i++) {
        a_pop.pop();
    }

    print("Pop Done in " + (Date.now() - start));

    start = Date.now();
    for(var i = 0; i < N; i++) {
        a_shift.shift();
    }
    print("Shift Done in " + (Date.now() - start));
}

main();