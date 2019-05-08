Resultados_hw2.pdf : Resultados_hw2.tex Señales.pdf Fourier_trans.pdf espectograma2señales.pdf temblor.pdf transfouriertemblor.pdf espectogramatemblor.pdf
	pdflatex Resultados_hw2.tex

Señales.pdf : Fourier.py signal.dat signalSuma.dat
	python Fourier.py

Fourier_trans.pdf : Fourier.py signal.dat signalSuma.dat
	python Fourier.py
    
espectograma2señales.pdf : Fourier.py signal.dat signalSuma.dat
	python Fourier.py   
    
temblor.png : Fourier.py temblor.txt
	python Fourier.py  
    
transfouriertemblor.pdf : Fourier.py temblor.txt
	python Fourier.py 

espectogramatemblor.pdf : Fourier.py temblor.txt
	python Fourier.py 

    
