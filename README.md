<h1>v1.1</h2>
<p>v1.1 šaka skirta palyginti "class" ir "struct" naudojimą talpinant studento duomenis. Tyrimas ir jo rezultatai pateikiami žemiau, v1.1 implementuota "class" lyginama su v1.0 versijoje naudotu "struct".</p>

<p>Tyrimas vykdytas su 3 strategija (žr. v1.0) bei vektoriaus konteineriu, vykdytos 3 iteracijos.</p>

<h3>"Class" ir "struct" | Tyrimo rezultatai  </h3>

| Programos veikimo laikas su CLASS | Programos veikimo laikas su STRUCT | Studentų kiekis | Optimizavimo vėliava | .exe failo dydis su CLASS (KB)| .exe failo dydis su STRUCT |
| ------ | ----- | --------------- | ------------------------ | ---- | ---- | 
| 0.434467s | 0.418547s | 100 000 | -O3 | 332 | ?
| 0.453639s | ? | 100 000 | -O2 | 319 | ? 
| 0.453065s | ? | 100 000 | -O1 | 317 | ?
| 1.54309s |?| 100 000 | - | 861 | ?
| 
| 1.95142s | 1.70978s | 1 000 000 | -O3 | 332 | ?
| 1.9155s | ? | 1 000 000 | -O2 | 319 | ?
| 1.93125s | ? | 1 000 000 | -O1 | 317 | ?
| 7.94422s | ? | 1 000 000 | - | 861 | ? 




