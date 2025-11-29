
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));

    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0;
    char komut;

    printf("HAYATTA KALMA SIMULATORU\n");
    printf("Komutlar: [A]vlan, [S]iginak, [E]nvanter, [R]Dinlen, [F]Tehlike, [P]Sifre, [X]Cikis\n");



    do {
        printf("\nNe yapmak istersin? > ");
        scanf(" %c", &komut);


        if(komut >= 'a' && komut <= 'z') {
            komut = komut - 32;
        }

        switch (komut) {

            case 'A':

                if (enerji >= 15) {
                    enerji -= 15;
                    printf("Avlanmaya ciktin... (Enerji -15)\n");

                    int sans = rand() % 100;
                    if (sans < 50) {
                        yemek++;
                        printf("BASARILI! Bir yemek buldun. (Yemek: %d)\n", yemek);
                    } else if (sans < 80) {
                        printf("Hicbir sey bulamadin.\n");
                    } else {

                        saglik -= 10;
                        printf("DIKKAT! Av sirasinda yaralandin. (Saglik -10)\n");
                    }
                } else {
                    printf("UYARI: Avlanmak icin yeterli enerjin yok! (Gereken: 15)\n");
                }
                break;

            case 'S':

                if (siginak == 1) {
                    printf("Zaten bir siginagin var.\n");
                } else {
                    enerji -= 10;
                    printf("Siginak ariyorsun... (Enerji -10)\n");

                    if ((rand() % 100) < 40) {
                        siginak = 1;
                        printf("TEBRIKLER! Guvenli bir siginak buldun.\n");
                    } else {
                        printf("Maalesef uygun bir yer bulamadin.\n");
                    }
                }
                break;

            case 'E':
                printf("--- DURUM RAPORU ---\n");
                printf("Saglik : %d\n", saglik);
                printf("Enerji : %d\n", enerji);
                printf("Yemek  : %d\n", yemek);
                printf("Siginak: %s\n", siginak == 1 ? "VAR" : "YOK");
                break;

            case 'R': // DÝNLEN

                if (siginak == 1) {
                    enerji += 20;
                    saglik += 10;
                    printf("Siginakta guvende uyudun. (Enerji +20, Saglik +10)\n");
                } else {
                    enerji += 10;
                    printf("Disarida dinlendin. (Enerji +10)\n");
                }

                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                break;

            case 'F':
                printf("!!! TEHLIKE DALGASI BASLIYOR !!!\n");
                for (int i = 1; i <= 3; i++) {
                    int hasar = rand() % 10 + 1;
                    saglik -= hasar;
                    printf("%d. Dalga: Vahsi hayvan saldirisi! (Saglik -%d)\n", i, hasar);

                    if (saglik <= 0) {
                        printf("OLDU! Tehlike dalgasina dayanamadin.\n");
                        komut = 'X';
                        break;
                }
                if (saglik > 0) printf("Tehlike dalgasini atlattin.\n");
                break;

            case 'P':
                {
                    int girilenSifre;
                    int gercekSifre = 1234;
                    printf("Kilitli bir kapi buldun. Gecmek icin sifreyi cozmelisin.\n");


                    do {
                        printf("Sifreyi Girin (4 haneli): ");
                        scanf("%d", &girilenSifre);

                        if (girilenSifre != gercekSifre) {
                            printf("Hatali sifre! Tekrar dene.\n");
                            enerji -= 5;
                        }
                    } while (girilenSifre != gercekSifre && enerji > 0);

                    if (enerji > 0) {
                        printf("BASARILI! Kapi acildi, yeni bir bolgeye gectin.\n");
                        yemek += 2;
                    } else {
                        printf("Enerjin tukendi, kapiyi acamadan bayildin.\n");
                    }
                }
                break;

            case 'X':
                printf("Simulasyondan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz komut! Lutfen A, S, E, R, F, P veya X girin.\n");
        }


        if (saglik <= 0 || enerji <= 0) {
            printf("\n--- OYUN BITTI ---\n");
            printf("Saglik veya Enerji kritik seviyenin altina dustu.\n");
            break; // Ana döngüyü kýrar
        }

    } while (komut != 'X');

    return 0;
}
