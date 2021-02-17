function reversed(arr){
	return [...arr].reverse().join(" ")
}
console.log(reversed(process.argv.slice(2)));
