
let f=10;

function ADD(x , y){
	let z=x+y;
	return z;
}


let v=ADD(5,6);

console.log(v);
console.log(f);

let arr=new Array();

for(let i=0;i<10;i++){
	arr.push(i);
}

for(e in arr){
	console.log(arr[e]);
}
 
 function even(x){
 	if(x%2===0)return true;
 	else return false;
 }

 let temp=arr.filter(even);
 for(e in temp){
	console.log(temp[e]);
}

let str="   abcd    ";
 console.log(str);
 let s=str.trim();
 console.log(s.toUpperCase());

 let emp={
 	id:1,
 	name:"Nitin Kumar Singh",
 	phone:9621417760
 };


 console.log(emp);
 let obj=new Object();
 obj.id=7;
 obj.name="king";
 obj.phone=98829;
 console.log(obj);

 function student(id,name,phone){
     this.id=id;
     this.name=name;
     this.phone=phone;
     this.changeId=changeId;
     function changeId(x){
     	this.id=x;
     }
 }

 let p=new student(10,"ollo",9080);
 console.log(p);
 p.changeId(12);
 console.log(p);

function ADD(){
	let x=parseInt(document.getElementById("num1").value);
	let y=parseInt(document.getElementById("num2").value);
 alert(x+y);
  let z=x+y;

}


//  let flag=true;
// function qw(){
// 	let data="Name:<input type='text' name='name'><br>Comment:<br><textarea rows='5' cols='80'></textarea>  <br><input type='submit' value='Post Comment'>";    
// 	if(flag){document.getElementById("mylocation").innerHTML=data;
// 	flag=false;
// }
// 	else {
// 		document.getElementById("mylocation").innerHTML="";
// 		flag=true;
// 	} 
// }
