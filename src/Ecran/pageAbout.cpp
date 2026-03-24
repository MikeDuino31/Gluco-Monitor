#include "Ecran/pageAbout.h"
#include "Ecran/Gestion.h"
#include <U8g2lib.h>
#include "Config.h"
#include "Langues/License.h"


static int16_t idxVisu = 0;
void Impression(int16_t delta);
void pageAboutSetup()
{
    PageActu = pageAbout;
    idxVisu=0;
    Impression(0);
}
void Impression(int16_t delta)
{
    CanvaBase->setTextColor(RGB565_WHITE);
    CanvaBase->fillScreen(RGB565_NAVY);
    CanvaBase->setCursor(0, 0);
    String Texte="";
    if (LaLangue==LANG_FR){
        Texte = String(Avertissement) + "       \n\n=== Licence ===\n" + License;
    } else {
        Texte = String(Disclaimer) + "     \n\n=== License ===\n" + License;
    }
    int16_t Lmax = Texte.length() - 100;
    int p = 0;
    idxVisu = idxVisu - delta;
    if (idxVisu < 0)
        idxVisu = 0;
    if (idxVisu > Lmax)
        idxVisu = Lmax;

    if (delta <= 0)
    {
        Texte = Texte.substring(idxVisu, idxVisu + 1000);
        p = Texte.indexOf("\n");
        if (p > 0)
            Texte = Texte.substring(p + 1);
        idxVisu = idxVisu + p + 1;
    }
    else
    {
        String T=Texte.substring(0,idxVisu);
        p = T.lastIndexOf("\n");
        idxVisu=p+1;
        Texte = Texte.substring(idxVisu, idxVisu + 1000);
    }
    CanvaBase->print(utf8ToLatin15(Texte));
    CanvaBase->flush();
}
void handleTouch_About(uint16_t touchX, uint16_t touchY, int16_t DeltaTouchY)
{
    int16_t delta = DeltaTouchY / 2;

    if (delta != 0)
    {

        Impression(delta);
    }
}