(function () {
	var n = parseInt(readline());
	var line = readline().split(' ');
	var m = {};
	var prefix = 0;
	var ans = n - 1;
	//print(n);
	for(var idx in line){
		prefix += parseInt(line[idx]);
		//print(prefix);
		if(!m[prefix]) {
			m[prefix] = 1;
		} else {
			++m[prefix];
		}
		ans = n - m[prefix] > ans? ans: n - m[prefix];
	}
	print(ans);
})();