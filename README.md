**Kompilator dla języka podobnego do Pascala**  

Ten projekt to kompilator dla języka programowania inspirowanego Pascalem. Analizuje składnię i generuje kod pośredni dla podstawowych konstrukcji językowych, takich jak:  

✅ Definicje programów, funkcji i procedur  
✅ Operacje arytmetyczne i logiczne  
✅ Instrukcje sterujące (`if-then-else`, `while-do`)  
✅ Operacje wejścia/wyjścia (`read`, `write`)  

Kompilator wykorzystuje **Flex** do analizy leksykalnej oraz **Bison** do analizy składniowej. Obsługuje zmienne globalne i lokalne oraz dynamiczne zarządzanie stosowym obszarem pamięci.  

🔧 **Jak używać?**  
1. Skompiluj kompilator przy użyciu `flex` i `bison`.  
2. Uruchom kompilator na pliku źródłowym napisanym w obsługiwanym języku.  
3. Analizuj wygenerowany kod pośredni.  

📌 **Planowane rozszerzenia**:  
🔹 Optymalizacja kodu pośredniego  
🔹 Rozszerzona obsługa typów danych  
🔹 Generacja kodu dla maszyn wirtualnych  

Zapraszamy do współpracy i zgłaszania sugestii! 🚀
