# QRCode ePaper for D1 mini (ESP8266)

## § 材料準備

1. [LOLIN D1 mini](https://wiki.wemos.cc/products:d1:d1_mini)
2. [TFT I2C Connector Shield](https://www.aliexpress.com/item/32846977179.html?storeId=1331105&spm=a2g1y.12024536.productList_2559252.subject_2)
3. [ePaper 2.13 Shield](https://wiki.wemos.cc/products:d1_mini_shields:epd_2.13_shield)
4. TFT e-Paper Cable

可以在 [WEMOS.CC](https://www.wemos.cc/) 找到這些零件的購買網址與詳細資訊。

> 購買網址：[LOLIN Official Store](https://lolin.aliexpress.com/store/1331105)

![零件](imgs/img1.jpg)

## § 組裝

將 TFT I2C Connector Shield 插到 D1 mini 上：

![D1 mini and TFT I2C Connector Shield](imgs/img2.jpg)


然後把 ePaper Shield 連接到 D1 mini：

![D1 mini and ePaper Shield](imgs/img3.jpg)

<br>


## § 設定 Arduino IDE 環境

1. 請先閱讀 [ESP8266 core for Arduino](https://github.com/esp8266/Arduino) 的 README.md，照裡頭的步驟安裝好 ESP8266 Board 套件。
2. 然後到 [WEMOS wiki](https://wiki.wemos.cc/downloads) 裡下載 Serial port Driver，並安裝之。
3. 把 D1 mini 連接到電腦上，然後克隆或是下載本 Repo，並用 Arduino IDE 開啟 `EPD_QR_8266.ino`。
4. 點選 Arduino IDE 選單 -> Sketch -> Include Library -> Manage Libraries...，然後搜尋並安裝以下程式庫：

    - Adafruit GFX Library (by Adafruit)
    - QRCode (by Richard Moore)

5. 下載 [LOLIN_EPD_Library](https://github.com/wemos/LOLIN_EPD_Library)，並用 Arduino IDE 選單 -> Sketch -> Include Library -> Add .ZIP Library... 安裝之。
6. 點選 Arduino IDE 選單 -> Tools -> Board: -> 選擇 `LOLIN(WEMOS) D1 mini Pro`； Upload Speed: -> 選擇 `115200`； CPU Frequency: -> 選擇 `80 MHz`。
7. 點選 Arduino IDE 選單 -> Tools -> Port，選擇連接 D1 mini 的 Serial port，Windows 上的名稱通常都是 COM`X`，Mac 上的名稱通常都是 /dev/cu.SLAB_USBtoUART 或是 /dev/cu.wchusbserial`XXXX` (X 為數字)。

<br>


## § 修改 AP 的 SSID 跟 Password

因為會把 D1 mini 變成一台 WiFi AP，你可以修改此處的 SSID 跟 Password：

![AP's SSID and Password](imgs/ap_ssid_pass.png)

<br>


## § 編譯並上傳程式

按下 Arduino IDE 的 Upload 按鈕，編譯並上傳程式到 D1 mini：

![upload-win](imgs/upload_win.png)

<br>


## § 連線到 AP

我們先連線到 AP (程式裡預設的 SSID 是 `EPD_SETUP_AP_8266`，密碼是 `pw112233`)，例如下圖：

![Connect to AP](imgs/connect_ap.jpg)

接著要開啟 QRCode Setup 網頁。開啟網頁瀏覽器，並輸入 Server 的 IP (Server IP 會在裝置啟動時顯示在 ePaper 上)：

![Server's IP](imgs/server_ip.jpg)

![Keyin Server IP](imgs/keyin_ip.jpg)

<br>


## § 設定 QRCode

開啟 QRCode Setup 網頁後，分別有網站網址、WiFi、純文字等 QRCode 類型，輸入資訊後，按下 `Update` 按鈕即可顯示/更新 QRCode：

![Setup QRCode](imgs/qrepd_web_setup.png)

<br>

如果勾選 `Display type`，那麼 QRCode 右方還會顯示類型的文字：

![Setup QRCode](imgs/qrepd_display_type.png)

<br>

沒有勾選 `Display type`，那麼 ePaper 只顯示 QRCode：

![Only QRCode](imgs/only_qr.jpg)

<br>

WiFi QRcode + 顯示類型文字：

![WiFi QRCode](imgs/wifi_qr.jpg)

純文字 QRcode + 顯示類型文字：

![Text QRCode](imgs/text_qr.jpg)

<br>


## § 拔掉電源

因為 ePaper 移除電源後，依然可以顯示最後一個呈現的畫面，所以我們設定好 QRCode 後，可以把 D1 mini 的電源移除，並將 TFT e-Paper Cable 拔掉，然後把 ePaper Shield 貼到牆上或是放到你想放置的地方：

![QRCode, Ok!](imgs/qrepd_ok.jpg)
