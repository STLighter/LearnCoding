var Step = 1025;
var Loop = 1024;
var N = Step * Loop;
var a_setL = [];
var a_unsetL = [];
function main() {
    var start = Date.now();
    a_setL.length = N;
    for(var i = Step - 1, tmp = 0; i < N; tmp += Step, i += Step) {
        for (var j = i; j >= tmp; j--) {
            a_setL[j] = j;
        }
    }

    print("Set Length Done in " + (Date.now() - start));

    start = Date.now();
    for(var i = Step - 1, tmp = 0; i < N; tmp += Step, i += Step) {
        for (var j = i; j >= tmp; j--) {
            a_unsetL[j] = j;
        }
    }
    print("Didn't Set Length Done in " + (Date.now() - start));
}

main();