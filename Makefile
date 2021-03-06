CXXFLAGS=-g -flto

CXXFLAGS=-O3 -s -flto

CXXFLAGS=-Os -s -flto -fno-stack-limit -ffast-math -fno-stack-protector -fno-stack-check \
		-fno-asynchronous-unwind-tables -fno-exceptions  -funsafe-math-optimizations -fomit-frame-pointer \
		-ffunction-sections -fdata-sections -fno-math-errno -fno-unroll-loops -fmerge-all-constants \
		-fno-ident -mfpmath=387 -mfancy-math-387 -Bmydir -fomit-frame-pointer -fsingle-precision-constant

LDFLAGS=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -Wl,--build-id=none -Wl,--hash-style=gnu \
		-Wl,-z,norelro -fuse-ld=gold

SRC=src
OBJ=obj

MAIN=$(OBJ)/gui.o $(OBJ)/vector2f.o $(OBJ)/guiWindow.o

SYNTH=$(OBJ)/synth.o $(OBJ)/channel.o $(OBJ)/decode.o $(OBJ)/envelope.o $(OBJ)/filter.o $(OBJ)/effect.o

GUI=$(OBJ)/lockbutton.o $(OBJ)/element.o $(OBJ)/button.o $(OBJ)/frame.o $(OBJ)/knob.o\
	$(OBJ)/vu.o $(OBJ)/slider.o $(OBJ)/label.o $(OBJ)/oscilloscope.o $(OBJ)/rotButton.o $(OBJ)/noteLabel.o

TARGETS=$(MAIN) $(GUI) $(SYNTH)

%/:
	mkdir -p $@

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)/
	$(CXX) -c $(CXXFLAGS) $< -o $@

gui: $(TARGETS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	chmod +x $@
	wc -c $@

gui.lzma: gui
	strip $< -S --strip-unneeded -R .eh_frame -R .eh_frame_hdr -R .gnu.version -R .note.ABI-tag \
	-R .note.gnu.gold-version  -R .comment
	sstrip -z $<
	wc -c $<
	./opt_lzma.py $< -o $@

gui.sh: gui.lzma
	cat shelldropper.sh $< > $@
	
gui.vdh: gui.lzma
	cat vondehi $< > $@

all:gui.sh gui.vdh
	chmod +x $^
	wc -c $^

clean:
	-rm -rfv gui gui.sh gui.vdh $(OBJ)/ *.lzma