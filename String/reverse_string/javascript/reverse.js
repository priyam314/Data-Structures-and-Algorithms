function reversed(s){
	return [...s].reverse().join("")
	
	//alternate ways for string to array 
	//1. s.split('')
	//2. Array.from(s)
	//3. Object([],s)
	//4. [...s] this is so far the best one
	
}
console.log(reversed(process.argv[2]));
