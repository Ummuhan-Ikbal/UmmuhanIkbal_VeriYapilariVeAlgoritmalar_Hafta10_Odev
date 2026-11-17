#include <stdio.h>
#include <stdbool.h>

#define V 5

// Şehir isimleri ve harf kodları
const char* sehirler[V] = {
    "A: Istanbul",
    "B: Ankara",
    "C: Izmir",
    "D: Bursa",
    "E: Antalya"
};
// Komşuluk Matrisi (0: A, 1: B, 2: C, 3: D, 4: E)
int graf[V][V] = {
    // A  B  C  D  E
    {  0, 1, 0, 1, 0 }, // A: İstanbul (Ankara ve Bursa'ya bağlı)
    {  1, 0, 1, 0, 1 }, // B: Ankara (İstanbul, İzmir ve Antalya'ya bağlı)
    {  0, 1, 0, 0, 0 }, // C: İzmir (Ankara'ya bağlı)
    {  1, 0, 0, 0, 1 }, // D: Bursa (İstanbul ve Antalya'ya bağlı)
    {  0, 1, 0, 1, 0 }  // E: Antalya (Ankara ve Bursa'ya bağlı)
};
// BFS (Genişlik Öncelikli Arama) - Queue (Kuyruk) Kullanır
void BFS(int baslangic) {
    bool ziyaretEdildi[V] = {false};
    int kuyruk[V];
    int on = 0, arka = 0;
    ziyaretEdildi[baslangic] = true;
    kuyruk[arka++] = baslangic;
    printf("BFS Dolasma Sirasi:\n");
    while (on < arka) {
        int mevcut = kuyruk[on++];
        printf("%s", sehirler[mevcut]);
        if (on < V) printf(" -> ");
        // Komşuları alfabetik (indeks) sırasıyla kuyruğa ekle
        for (int i = 0; i < V; i++) {
            if (graf[mevcut][i] == 1 && !ziyaretEdildi[i]) {
                ziyaretEdildi[i] = true;
                kuyruk[arka++] = i;
            }
        }
    }
    printf("\n\n");
}
// DFS (Derinlik Öncelikli Arama) - Özyineleme (Recursion / Stack) Kullanır
void DFS_Yardimci(int dugum, bool ziyaretEdildi[]) {
    ziyaretEdildi[dugum] = true;
    printf("%s -> ", sehirler[dugum]);

    for (int i = 0; i < V; i++) {
        if (graf[dugum][i] == 1 && !ziyaretEdildi[i]) {
            DFS_Yardimci(i, ziyaretEdildi);
        }
    }
}
void DFS(int baslangic) {
    bool ziyaretEdildi[V] = {false};
    printf("DFS Dolasma Sirasi:\n");
    DFS_Yardimci(baslangic, ziyaretEdildi);
    printf("BITTI\n");
}
int main() {
    // 0. indeks olan A: İstanbul'dan başlıyoruz
    BFS(0);
    DFS(0);
    return 0;
}