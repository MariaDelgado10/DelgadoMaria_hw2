Resultados_hw2.pdf : Resultados_hw2.tex Señales.png Fourier_trans.png  espectograma2señales.png temblor.png transfouriertemblor.png espectogramatemblor.png
    pdflatex Resultados_hw2.tex

Señales.png : Fourier.py signal.dat signalSuma.dat
    python Fourier.py

Fourier_trans.png : Fourier.py signal.dat signalSuma.dat
    python Fourier.py
    
espectograma2señales.png : Fourier.py signal.dat signalSuma.dat
    python Fourier.py   
    
temblor.png : Fourier.py temblor.txt
    python Fourier.py  
    
transfouriertemblor.png : Fourier.py temblor.txt
    python Fourier.py 

espectogramatemblor.png : Fourier.py temblor.txt
    python Fourier.py 

    