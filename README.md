# Sudoku Oyunu / Sudoku Game

Bu proje, C dilinde yazılmış tam özellikli bir konsol tabanlı Sudoku oyunudur.

*This project is a fully-featured console-based Sudoku game written in C.*

## Özellikler / Features

### 🎮 Temel Özellikler / Core Features
- **Tam Sudoku puzzle oluşturma**: Geçerli ve çözülebilir puzzlelar otomatik olarak oluşturulur
- **4 farklı zorluk seviyesi**: Baby, Easy, Hard, Impossible
- **İnteraktif gameplay**: Sayı yerleştirme, silme ve doğrulama
- **Zaman takibi**: Oyun süreniz otomatik olarak ölçülür
- **Skor kaydetme**: En iyi zamanlarınızı kaydedin ve görüntüleyin
- **Renkli arayüz**: ANSI renk kodları ile geliştirilmiş görsellik

### 🎯 Zorluk Seviyeleri / Difficulty Levels
- **Baby**: 15 boş hücre (yeni başlayanlar için)
- **Easy**: 30 boş hücre (kolay seviye)
- **Hard**: 30 boş hücre (zor seviye)
- **Impossible**: 40 boş hücre (uzman seviye)

## Kurulum ve Çalıştırma / Installation and Running

### Gereksinimler / Requirements
- GCC compiler veya herhangi bir C compiler
- Terminal/Command Prompt erişimi
- Windows veya Unix/Linux işletim sistemi

### Derleme / Compilation
```bash
gcc -o sudoku sudoku.c
```

### Çalıştırma / Running
```bash
./sudoku          # Linux/Mac
sudoku.exe        # Windows
```

## Nasıl Oynanır / How to Play

### 1. Ana Menü / Main Menu
Oyunu başlattığınızda 3 seçenekle karşılaşacaksınız:
- **1) New Game**: Yeni oyun başlatır
- **2) Scores**: Önceki skorları görüntüler
- **3) Exit**: Oyundan çıkar

### 2. Zorluk Seçimi / Difficulty Selection
4 farklı zorluk seviyesinden birini seçin.

### 3. Oyun Oynama / Playing the Game
- **Satır giriniz**: 1-9 arası satır numarası
- **Sütun giriniz**: 1-9 arası sütun numarası  
- **Değer giriniz**: 1-9 arası sayı (silmek için 0)

### 4. Oyun Kuralları / Game Rules
- Her satırda 1-9 arası her sayı sadece bir kez bulunabilir
- Her sütunda 1-9 arası her sayı sadece bir kez bulunabilir
- Her 3x3 kutuda 1-9 arası her sayı sadece bir kez bulunabilir

## Dosya Yapısı / File Structure

```
sudoku/
├── sudoku.c          # Ana kaynak kod dosyası
├── scores.txt        # Skor kayıtları (otomatik oluşturulur)
└── README.md         # Bu dosya
```

## Fonksiyonlar / Functions

### Ana Fonksiyonlar / Main Functions
- `main()`: Program giriş noktası
- `menu()`: Ana menü işlemleri
- `oyun()`: Sudoku puzzle oluşturma
- `zorluk()`: Zorluk seviyesi ayarlama
- `oyuncu()`: Oyuncu etkileşimi
- `show()`: Oyun tahtasını görüntüleme
- `kotrol()`: Oyun doğrulama
- `kayit()`: Skor kaydetme
- `scores()`: Skorları görüntüleme

### Yardımcı Fonksiyonlar / Helper Functions
- `clearScreen()`: Ekranı temizleme (cross-platform)
- `waitForEnter()`: Kullanıcı girişi bekleme

## Teknik Detaylar / Technical Details

### Algoritma / Algorithm
1. **Puzzle Oluşturma**: Backtracking algoritması ile geçerli bir tam Sudoku oluşturulur
2. **Boş Hücre Yaratma**: Seçilen zorluk seviyesine göre rastgele hücreler boşaltılır
3. **Doğrulama**: Her hamle sonrası Sudoku kuralları kontrol edilir

### Veri Yapıları / Data Structures
- `alan[11][9]`: Ana oyun tahtası (11x9 array)
  - `alan[0-8][0-8]`: Sudoku ızgarası
  - `alan[9][0-8]`: Sayı referansı (1-9)
  - `alan[10][0-8]`: Kullanılabilir sayı sayacı

### Platform Desteği / Platform Support
- **Windows**: `system("cls")` ile ekran temizleme
- **Unix/Linux**: `system("clear")` ile ekran temizleme

## Örnek Oyun / Example Game

<img width="485" height="643" alt="image" src="https://github.com/user-attachments/assets/f477e608-ba47-4172-a15f-819eff10bdae" />


## Gelecek Geliştirmeler / Future Enhancements

- [ ] GUI arayüzü
- [ ] Daha fazla zorluk seviyesi
- [ ] İpucu sistemi
- [ ] Geri alma (undo) özelliği
- [ ] Oyun kaydetme/yükleme
- [ ] Çoklu dil desteği

## Katkıda Bulunma / Contributing

Bu projeye katkıda bulunmak isterseniz:
1. Fork yapın
2. Feature branch oluşturun (`git checkout -b feature/AmazingFeature`)
3. Değişikliklerinizi commit edin (`git commit -m 'Add some AmazingFeature'`)
4. Branch'inizi push edin (`git push origin feature/AmazingFeature`)
5. Pull Request açın

## Lisans / License

Bu proje açık kaynak kodludur ve herkes tarafından kullanılabilir.

## Sorun Giderme / Troubleshooting

### Yaygın Problemler / Common Issues

**Derleme Hatası / Compilation Error:**
```bash
# Linux/Mac için
gcc -std=c99 -o sudoku sudoku.c

# Ek kütüphaneler gerekiyorsa
gcc -std=c99 -lm -o sudoku sudoku.c
```

**Karakter Kodlama Sorunu / Character Encoding Issue:**
Terminal'inizin UTF-8 desteklediğinden emin olun.

**Skor Dosyası Oluşturulamıyor / Cannot Create Score File:**
Programın çalıştırıldığı dizinde yazma izniniz olduğundan emin olun.

## İletişim / Contact

Sorularınız veya önerileriniz için lütfen bir issue açın.

---

**Not**: Bu oyun eğitim amaçlı geliştirilmiştir ve C programlama dilinin temel özelliklerini göstermektedir.
