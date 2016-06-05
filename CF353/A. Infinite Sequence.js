(function () {
	var line = readline().split(' ');
	var a = parseInt(line[0]);
	var b = parseInt(line[1]);
	var c = parseInt(line[2]);
	var x = b-a;
	if(x==0 || (c!=0 && x%c == 0 && x/c>0))
		print("YES");
	else print("NO");
})();