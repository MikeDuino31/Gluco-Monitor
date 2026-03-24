// language=JavaScript
static const char *JS_Commun = R"JS(
function GID(id) { return document.getElementById(id); }
function GH(id, T) {
    if (GID(id)) {
        GID(id).innerHTML = T;
    }
}
function GV(id, T) { GID(id).value = T; }
let T;

async function chargerLangue() {
    const response = await fetch('Langue.json');
    const Traduction = await response.json();

    // Accès aux clés
    console.log(Traduction);
    document.querySelectorAll('[data-i18n]').forEach(el => {
        const key = el.getAttribute('data-i18n'); // Récupère les attributs
        el.textContent = Traduction[key];       // Injecte "Bienvenue chez vous !"
    });

}


)JS";