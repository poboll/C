// ==/UserScript==
 
(function() {
  'use strict';

  // Your code here...
  var flag=false
  var second=0
  var catidArr=[134,135,136,137]
  var currIndex=0
  var onlineLearn = setInterval(()=>{
      if(flag==false&&second<=4800){
          $.ajax({
http://xsyzc.gzcc.cn/index.php?m=member&c=study&a=enter&catid=136 
          url: "/index.php?m=member&c=study&a=enter",
          dataType: "json",
          type: "get",
          data: {
              catid: catidArr[currIndex],
          },
          success: function (res) {
              second=res.seconded
              if(res.onlining=="1"){
                  $.ajax({
                  url: "/index.php?m=member&c=study&a=close",
                  dataType: "json",
                  type: "get",
                  data: {
                      catid: catidArr[currIndex],
                      second: second
                  },
                  success: function () {
                      loadRecord(catidArr[currIndex])
                  }
                  });
              }
              flag=true
          }
          });
      }else if(second>4800){
          $.ajax({
              url: "/index.php?m=member&c=study&a=close",
              dataType: "json",
              type: "get",
              data: {
                  catid: catidArr[currIndex],
                  second: second
              },
              success: function () {
                  loadRecord(catidArr[currIndex])
              }
              });
          currIndex++;
          flag=false;
          second=0;
      }
      else if(currIndex==4){
          //清除定时
          clearInterval(onlineLearn)
          alert("全部看完了！")
      }
      else{
          second++;
      }
      console.log("当前秒数："+second)
  },1000)
})();