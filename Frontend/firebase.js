const firebaseConfig = {
    apiKey: "AIzaSyCPQuapEWZlBIfGc5dN0cxj3kDm16gcem8",
    authDomain: "fire-alarm-system-c4407.firebaseapp.com",
    databaseURL: "https://fire-alarm-system-c4407-default-rtdb.firebaseio.com",
    projectId: "fire-alarm-system-c4407",
    storageBucket: "fire-alarm-system-c4407.appspot.com",
    messagingSenderId: "134607759185",
    appId: "1:134607759185:web:17024c62504aac4ad51570",
};
firebase.initializeApp(firebaseConfig);


function getdatastatus() {
    const dbRefCanhBao = firebase.database().ref().child('StatusFire');
    dbRefCanhBao.on('value', snap => {
        var canhbao = snap.val();
        document.getElementById('status').innerHTML = canhbao;
    });
}


function dongho() {
    var time = new Date();
    var gio = time.getHours();
    var phut = time.getMinutes();
    var giay = time.getSeconds();
    if (gio < 10) {
        gio = "0" + gio;
    }
    if (phut < 10) {
        phut = "0" + phut;
    }
    if (giay < 10) {
        giay = "0" + giay;
    }
    var calendar = new Date();
    var thu = ["Chủ Nhật", "Thứ 2", "Thứ 3", "Thứ 4", "Thứ 5", "Thứ 6", "Thứ 7"];
    var thang = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", ];

    document.getElementById("datetime").innerHTML = thu[calendar.getDay()] + " ngày " + calendar.getDate() +
        " tháng " + thang[calendar.getMonth()] + " năm  " + calendar.getFullYear() +
        " " + gio + ":" + phut + ":" + giay;
    setTimeout("dongho()", 1000);
}