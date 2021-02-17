import std.stdio;
import std.algorithm.mutation;
void main(string[] args){
	for(int i=1;i<args.length;i++){
		writeln(args[i].dup.reverse);
	}
	
}
