import 'dart:io';

main(){
	var arr1 = stdin.readLineSync();
	arr1 = arr1.split(" ").map(int.parse).toList();
	var arr2 = stdin.readLineSync();
	arr2 = arr2.split(" ").map(int.parse).toList();

	int i =0,j=0,count = 0;
	
	while(i<arr1.length && j<arr2.length){
		if (int.parse(arr1[i])<int.parse(arr2[j])){
			print("${arr1[i++]} ");
		}else if(int.parse(arr1[i])>int.parse(arr2[j])){
			print("${arr2[j++]} ");
		}else{
			print("${arr2[j++]} ");
			i++;
		}
		count++;
	}
	while(i<arr1.length){
		print("${arr1[i++]} ");
		count++;
	}
	while(j<arr2.length){
		print("${arr2[j++]} ");
		count++;
	}
	print("\n${count}");
	
}




