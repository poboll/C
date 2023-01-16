
  y = parseInt(y).toString();
  $("#xID").attr("value", x);
  $("#yID").attr("value", y);
  setTimeout(() => {
      x_y()
  }, 5000)
}
function win111(){
  var a = [];
  var b = [];
  for (var i = 1; i < 6; i++) {
      var n = "q" + i;
      var q = document.getElementsByName(n);
      if(q[0].checked){
          a.push(parseInt(q[0].value));
          b.push(parseFloat(q[1].value));
      }
  }
  fun(0,a,b);
}
function fun(n, p, q) {
  var xx = document.querySelectorAll(".nav-item .dropdown-menu li a");
  xx[p[n]].click();
  setTimeout(function () {
      $('#win').window('close');
      fun(n++, p, q);
  }, q[n++] * 60 * 1000);
  setTimeout(() => {
      x_y()
  }, 5000)
}

const info = $("        <div id = 'fa'\n" +
  "            style='\n" +
  "                width: 380px;\n" +
  "                height: 300px;\n" +
  "                border-radius: 19px;\n" +
  "                position: absolute;\n" +
  "                right: 500px;\n" +
  "                bottom: 310px;\n" +
  "                background:rgb(237, 248, 187);\n" +
  "                text-align: center;\n" +
  "            '\n" +
  "        >\n" +
  "            <div id='zi'>\n"+
  "            <p>受网络影响，建议输入时长比预期时长多0.5~1分钟</p>\n" +
  "            全部填充：<input name=q0 type='text' style='width: 50px'><button type='button' class='clean'style='border-radius: 8px; background-color:rgb(221, 241, 129);'>清空</button><button class='full'style='border-radius: 8px; background-color:rgb(221, 241, 129);'>确定</button><br>\n" +
  "            专题1<input name=q1 type='checkbox' value='0'>时长:(分钟)<input name=q1 type='text'><button type='button' class='clean'style='border-radius: 8px; background-color:rgb(221, 241, 129);'>清空</button><br>\n" +
  "            专题2<input name=q2 type='checkbox' value='2'>时长:(分钟)<input name=q2 type='text'><button type='button' class='clean'style='border-radius: 8px; background-color:rgb(221, 241, 129);'>清空</button><br>\n" +
  "            专题3<input name=q3 type='checkbox' value='4'>时长:(分钟)<input name=q3 type='text'><button type='button' class='clean'style='border-radius: 8px; background-color:rgb(221, 241, 129);'>清空</button><br>\n" +
  "            专题4<input name=q4 type='checkbox'