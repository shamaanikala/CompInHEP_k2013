SRC = $(basename $(wildcard *.tex))

all:
	$(MAKE) -i tex
	$(MAKE) mf
	$(MAKE) tex
	$(MAKE) bibtex
	$(MAKE) tex
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) ps2pdf

tex:
	latex $(SRC)

mf:
	mf "\mode=localfont; input electron_positron1.mf;"
	mf "\mode=localfont; input electron_positron2.mf;"

bibtex:
	bibtex $(SRC)

dvips:
	dvips $(SRC) -o

ps2pdf:
	ps2pdf $(SRC).ps $(SRC).pdf

RM = $(sort $(wildcard *.dvi *.log *.bbl *.blg  *.aux electron_positron* *~))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean
	rm *.ps

test:
	echo $(SRC)
