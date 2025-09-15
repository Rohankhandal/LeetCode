/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var intersection = function(nums) {
    // var ans=[];
    // var i=0;
    // for(var num of nums[0]){
    //     // console.log(num);
    //     var flag=true;
    //     for(var i=1;i<nums.length;i++){
    //         if(!nums[i].includes(num)){
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag) ans.push(num);
    // }
    // ans.sort((a,b)=>a-b);
    // return ans;


    let freq=new Map();
    let k=nums.length;

    for(let arr of nums){
        let unique= new Set(arr);
        for(let num of unique){
            if (freq[num] === undefined) {
                freq[num] = 1;
            } else {
                freq[num] = freq[num] + 1;
            }
        }
    }

    // collect numbers that appear in all arrays
    let ans = [];
    for (let num in freq) {
        if (freq[num] === k) {
            ans.push(Number(num));
        }
    }

    ans.sort((a, b) => a - b);   // sort in ascending order
    return ans;
};