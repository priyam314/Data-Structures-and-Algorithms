# command line input
# n k
n = parse(Int64,ARGS[1])
k = parse(Int64,ARGS[2])
if k>=n
	println([])
else
	temp = collect(1:n)
	tempSlice = collect(1:0)
	for i=1:round(Int64,k/2)+1
		if temp[i]==temp[k-i+2]
			push!(tempSlice,temp[i])
		end
		push!(tempSlice,temp[i],temp[k-i+2])
	end
	for i=1:(k+1)
		temp[i]=tempSlice[i]
	end
	println(temp)
end
	

	
