//
// HTML String
//

const char *homepage_html = R""""(
<!doctype html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>QRCode ePaper</title>

  <style>
  body {font-family: Arial;}
  h2 {
    margin-left: 25px;
    margin-bottom: 25px;
  }
  .tab {
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #f1f1f1;
    margin-left: 20px;
    margin-right: 20px;
  }
  .tab button {
    background-color: inherit;
    float: left;
    border: none;
    outline: none;
    cursor: pointer;
    padding: 14px 16px;
    transition: 0.3s;
    font-size: 17px;
  }
  .tab button:hover {
    background-color: #ddd;
  }
  .tab button.active {
    background-color: #ccc;
  }
  .tabcontent {
    display: none;
    padding: 6px 12px;
    border: 1px solid #ccc;
    border-top: none;
    padding: 20px 20px 20px 20px;
    margin-left: 20px;
    margin-right: 20px;
  }
  .updatebutton {
    width: 80px;
    font-size: 1.1em;
  }
  </style>
</head>
<body>
<h2>QRCode Setup</h2>
<div class="tab">
  <button id='website_btn' class="tablinks" onclick="openBtn(event, 'WebSite')">WebSite</button>
  <button class="tablinks" onclick="openBtn(event, 'WiFi')">WiFi</button>
  <button class="tablinks" onclick="openBtn(event, 'PlainText')">PlainText</button>
</div>
<div id="WebSite" class="tabcontent">
  <form action="/website" method="get">
    URL : <input type="text" name="url" size="30" value="http://"><br><br>
    <input type="checkbox" name="displaytype" value="yes"> Display type<br><br>
    <input type="submit" class="updatebutton" value="Update">
  </form>
</div>
<div id="WiFi" class="tabcontent">
  <form action="/wifi" method="get">
    <input type="radio" name="auth_type" value="WPA" checked> WPA / WPA2
    <input type="radio" name="auth_type" value="WEP"> WEP<br><br>
    SSID :<br>
    <input type="text" name="ssid"><br><br>
    Password :<br>
    <input type="text" name="passwd"><br><br>
    <input type="checkbox" name="displaytype" value="yes"> Display type<br><br>
    <input type="submit" class="updatebutton" value="Update">
  </form>
</div>
<div id="PlainText" class="tabcontent">
  <form action="/plaintext" method="get">
    Content :<br>
    <textarea name="content" rows="6" cols="35"></textarea><br><br>
    <input type="checkbox" name="displaytype" value="yes"> Display type<br><br>
    <input type="submit" class="updatebutton" value="Update">
  </form>
</div>
</body>
<script>
  function openBtn(evt, tabName) {
    var i, tabcontent, tablinks;
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
      tabcontent[i].style.display = "none";
    }
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
      tablinks[i].className = tablinks[i].className.replace(" active", "");
    }
    document.getElementById(tabName).style.display = "block";
    evt.currentTarget.className += " active";
  }
document.getElementById("website_btn").click();
</script>
</html>
)"""";
