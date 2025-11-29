#include <stdio.h>
#include <stdlib.h> // rand ve srand için
#include <time.h>   // Rastgele sayı üretimi için zaman fonksiyonu

/*
 * Proje: Karakter Tabanlı Hayatta Kalma Simülatörü
 * Açıklama: C dili temel yapıları kullanılarak geliştirilen metin tabanlı oyun.
 */

int main() {
    // Rastgele sayı üretimi için başlangıç (Seed)
    srand(time(0));

    // Durum Değişkenleri [cite: 22]
    int saglik = 100;    // 0-100 arası
    int enerji = 100;    // 0-100 arası
    int yemek = 0;       // Toplanan yemek sayısı
    int siginak = 0;     // 0: Yok, 1: Var [cite: 26]
    char komut;          // Kullanıcıdan alınacak işlem karakteri

    printf("--- HAYATTA KALMA SIMULATORU ---\n");
    printf("Komutlar: [A]vlan, [S]iginak, [E]nvanter, [R]Dinlen, [F]Tehlike, [P]Sifre, [X]Cikis\n");

    // OYUN DÖNGÜSÜ (DO-WHILE) [cite: 7]
    // Oyuncu 'X' komutunu vermediği sürece oyun devam eder.
    do {
        printf("\nNe yapmak istersin? > ");
        scanf(" %c", &komut); // Boşluk karakterini atlamak için %c önüne boşluk konuldu.

        // Küçük harf girilirse büyük harfe çevir (Kullanıcı dostu olması için)
        if(komut >= 'a' && komut <= 'z') {
            komut = komut - 32;
        }

        // KOMUT SİSTEMİ (SWITCH-CASE) [cite: 9]
        switch (komut) {
            
            case 'A': // AVLANMA
                // Aritmetik ve Mantıksal Operatörler [cite: 13]
                if (enerji >= 15) {
                    enerji -= 15; // Enerji harcanır
                    printf("Avlanmaya ciktin... (Enerji -15)\n");

                    // %50 şans ile yemek bulma (IF-ELSE Yapısı)
                    int sans = rand() % 100;
                    if (sans < 50) {
                        yemek++;
                        printf("BASARILI! Bir yemek buldun. (Yemek: %d)\n", yemek);
                    } else if (sans < 80) {
                        printf("Hicbir sey bulamadin.\n");
                    } else {
                        // %20 ihtimalle yaralanma
                        saglik -= 10;
                        printf("DIKKAT! Av sirasinda yaralandin. (Saglik -10)\n");
                    }
                } else {
                    printf("UYARI: Avlanmak icin yeterli enerjin yok! (Gereken: 15)\n");
                }
                break;

            case 'S': // SIĞINAK ARA
                // Mantıksal operatörlerle sığınak bulma şansı [cite: 14]
                if (siginak == 1) {
                    printf("Zaten bir siginagin var.\n");
                } else {
                    enerji -= 10;
                    printf("Siginak ariyorsun... (Enerji -10)\n");
                    // %40 şansla sığınak bulma
                    if ((rand() % 100) < 40) {
                        siginak = 1;
                        printf("TEBRIKLER! Guvenli bir siginak buldun.\n");
                    } else {
                        printf("Maalesef uygun bir yer bulamadin.\n");
                    }
                }
                break;

            case 'E': // ENVANTER GÖRÜNTÜLE [cite: 11]
                printf("--- DURUM RAPORU ---\n");
                printf("Saglik : %d\n", saglik);
                printf("Enerji : %d\n", enerji);
                printf("Yemek  : %d\n", yemek);
                printf("Siginak: %s\n", siginak == 1 ? "VAR" : "YOK");
                break;

            case 'R': // DİNLEN
                // Sığınak varsa daha iyi dinlenir, yoksa az dinlenir (IF-ELSE) [cite: 14]
                if (siginak == 1) {
                    enerji += 20;
                    saglik += 10;
                    printf("Siginakta guvende uyudun. (Enerji +20, Saglik +10)\n");
                } else {
                    enerji += 10;
                    printf("Disarida dinlendin. (Enerji +10)\n");
                }
                // Sınır Kontrolü (Aritmetik kontrol)
                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                break;

            case 'F': // TEHLİKE SERİSİ (FOR DÖNGÜSÜ) [cite: 16]
                printf("!!! TEHLIKE DALGASI BASLIYOR !!!\n");
                for (int i = 1; i <= 3; i++) {
                    int hasar = rand() % 10 + 1; // 1-10 arası hasar
                    saglik -= hasar;
                    printf("%d. Dalga: Vahsi hayvan saldirisi! (Saglik -%d)\n", i, hasar);
                    
                    if (saglik <= 0) {
                        printf("OLDU! Tehlike dalgasina dayanamadin.\n");
                        komut = 'X'; // Oyunu bitirmek için
                        break; // Döngüden çık
                    }
                }
                if (saglik > 0) printf("Tehlike dalgasini atlattin.\n");
                break;

            case 'P': // ŞİFRELİ İLERLEME (DO-WHILE İÇ İÇE) [cite: 19]
                {
                    int girilenSifre;
                    int gercekSifre = 1234;
                    printf("Kilitli bir kapi buldun. Gecmek icin sifreyi cozmelisin.\n");
                    
                    // Doğru şifre girilene kadar dönen döngü [cite: 20]
                    do {
                        printf("Sifreyi Girin (4 haneli): ");
                        scanf("%d", &girilenSifre);
                        
                        if (girilenSifre != gercekSifre) {
                            printf("Hatali sifre! Tekrar dene.\n");
                            enerji -= 5; // Ceza olarak enerji düşer
                        }
                    } while (girilenSifre != gercekSifre && enerji > 0);

                    if (enerji > 0) {
                        printf("BASARILI! Kapi acildi, yeni bir bolgeye gectin.\n");
                        yemek += 2; // Ödül
                    } else {
                        printf("Enerjin tukendi, kapiyi acamadan bayildin.\n");
                    }
                }
                break;

            case 'X': // ÇIKIŞ
                printf("Simulasyondan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz komut! Lutfen A, S, E, R, F, P veya X girin.\n");
        }

        // Oyun Bitiş Kontrolü
        if (saglik <= 0 || enerji <= 0) {
            printf("\n--- OYUN BITTI ---\n");
            printf("Saglik veya Enerji kritik seviyenin altina dustu.\n");
            break; // Ana döngüyü kırar
        }

    } while (komut != 'X'); // [cite: 7]

    return 0;
}