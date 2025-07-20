# 🚨 ESP32 Gas Leak Detector with Telegram Alert

Sistem deteksi kebocoran gas berbasis **ESP32** dengan sensor **MQ-2**, dilengkapi **buzzer** dan **LED** sebagai alarm lokal serta **notifikasi otomatis ke Telegram** jika terdeteksi gas berbahaya.

![Project Banner](https://img.shields.io/badge/ESP32-Gas--Leak--Notifier-green?style=for-the-badge&logo=arduino)
![License](https://img.shields.io/badge/license-MIT-blue?style=for-the-badge)

---

## 🔧 Hardware yang Dibutuhkan

| Komponen         | Jumlah | Keterangan                      |
|------------------|--------|----------------------------------|
| ESP32            | 1      | Modul mikrokontroler            |
| Sensor MQ-2      | 1      | Sensor gas LPG/CO/Asap          |
| Buzzer           | 1      | Alarm suara                     |
| LED              | 1      | Indikator visual                |
| Breadboard + kabel jumper | - | Untuk menyusun rangkaian |

---

## 📲 Fitur Utama

- 🔍 **Mendeteksi kebocoran gas** secara real-time.
- 🔔 **Buzzer & LED** aktif saat gas melebihi ambang batas.
- 📩 **Mengirim notifikasi otomatis ke Telegram** setiap 10 detik saat terdeteksi kebocoran.
- 🌐 **Koneksi WiFi** (bisa diuji di simulasi seperti Wokwi atau perangkat nyata).

---

## 🖥️ Skema Koneksi

```

MQ-2 A0 → GPIO 34 (Analog)
Buzzer  → GPIO 25
LED     → GPIO 26

````

---

## 💡 Cara Kerja

1. ESP32 membaca nilai dari sensor gas MQ-2.
2. Jika nilai gas melebihi ambang batas (misal: `3497`, setara ~200ppm):
   - Buzzer dan LED akan menyala.
   - Setiap 10 detik, sistem akan mengirim notifikasi ke Telegram.
3. Jika tidak ada gas terdeteksi, sistem akan tetap diam.

---

## 🧠 Logika Kode

```cpp
if (gasValue > 3497) {
  // Aktifkan buzzer dan LED
  // Kirim notifikasi jika sudah 10 detik sejak notifikasi terakhir
}
````

Notifikasi akan dikirim menggunakan endpoint:

```
https://api.telegram.org/bot<BOT_TOKEN>/sendMessage?chat_id=<CHAT_ID>&text=...
```

---

## ☁️ Setup Telegram Bot

1. Buka Telegram, cari **@BotFather**, buat bot baru dan salin `BOT_TOKEN`.
2. Cari `@userinfobot` untuk mendapatkan `CHAT_ID`.
3. Uji endpoint via browser untuk memastikan token dan chat ID benar.

---

## 🚀 Cara Menjalankan

1. Upload sketch `.ino` ke ESP32.
2. Sambungkan ke WiFi (`ssid` dan `password` sudah diatur).
3. Pantau Serial Monitor dan cek Telegram Anda.

---

## 📝 Contoh Notifikasi

> ⚠️ Gas terdeteksi! Nilai: 3610

---

## 🛡️ Lisensi

Proyek ini dilisensikan di bawah lisensi MIT. Silakan gunakan, modifikasi, dan distribusikan sesuai kebutuhan.

---

## 🤝 Kontribusi

Kontribusi sangat terbuka! Silakan fork, buka pull request, atau diskusikan fitur baru via issue.

---

## 📷 Screenshot

![Serial Monitor](docs/serial_monitor_example.png)
![Telegram Alert](docs/telegram_example.png)

---

## 🤛 Tentang Pengembang

👨‍💻 Mohammad Usman Asegaf
📍 Bandung, Indonesia
📚 Mahasiswa Teknik Informatika
🔗 GitHub: [@usmanasegaf](https://github.com/usmanasegaf)

---

