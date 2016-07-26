(function () {
	var n = parseInt(readline());
	var arr = readline().split(' ').map(function (ele) {
		return parseInt(ele);
	});
	var x = arr.indexOf(1) + 1;
	var y = arr.indexOf(n) + 1;
	var ans = y > x? (y - 1 > n - x ? y - 1: n - x) : (x - 1 > n - y ? x - 1: n - y);
	print(ans);
})()