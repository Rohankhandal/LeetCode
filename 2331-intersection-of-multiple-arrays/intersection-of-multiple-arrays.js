/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var intersection = function(nums) {
    var ans=[];
    var i=0;
    for(var num of nums[0]){
        console.log(num);
        var flag=true;
        for(var i=1;i<nums.length;i++){
            if(!nums[i].includes(num)){
                flag=false;
                break;
            }
        }
        if(flag) ans.push(num);
    }
    ans.sort((a,b)=>a-b);
    return ans;
};