# Survival-Simulator-C

# Karakter Tabanlı Hayatta Kalma Simülatörü (C Language)

Bu proje, C programlama dili kullanılarak geliştirilmiş metin tabanlı (text-based) bir hayatta kalma simülasyonudur. Proje, temel algoritma becerilerini, döngüleri, koşullu ifadeleri ve durum yönetimini sergilemek amacıyla hazırlanmıştır.

## 🎮 Oyunun Amacı
Oyuncu, kısıtlı kaynaklara (sağlık ve enerji) sahip bir karakteri yönetir. Amaç; avlanarak, sığınak bularak ve tehlikelerden kaçınarak hayatta kalmaktır.

## 🛠 Kullanılan Teknolojiler ve Yapılar
Proje saf **C dili** ile yazılmıştır ve aşağıdaki yapıları içerir:
- **Switch-Case:** Kullanıcı komutlarının (A, S, R vb.) yönetimi.
- **Do-While Döngüsü:** Oyunun ana döngüsü ve şifre doğrulama sistemi.
- **For Döngüsü:** Belirli sayıda tekrarlanan tehlike dalgası simülasyonu.
- **If-Else & Mantıksal Operatörler:** Olasılık hesaplamaları (yemek bulma şansı) ve durum kontrolleri.

## 🕹 Komutlar
| Tuş | İşlev | Açıklama |
| :--- | :--- | :--- |
| **A** | Avlan | Enerji harcar, yemek bulma şansı yaratır. |
| **S** | Sığınak Ara | Güvenli dinlenme için sığınak arar. |
| **R** | Dinlen | Enerji ve sağlık yeniler (Sığınak varsa daha etkili). |
| **E** | Envanter | Mevcut sağlık, enerji ve yemek durumunu gösterir. |
| **F** | Tehlike | 3 dalgalık bir saldırı simülasyonu başlatır. |
| **P** | Şifre | Kilitli bir kapıyı açmak için şifre çözme mini oyunu. |
| **X** | Çıkış | Simülasyonu sonlandırır. |

## 🚀 Kurulum ve Çalıştırma
1. Bu repoyu klonlayın veya `main.c` dosyasını indirin.
2. Bir C derleyicisi (GCC, Visual Studio, Dev-C++) ile dosyayı açın.
3. Kodu derleyin ve çalıştırın.
