SRC := src
IDIR := inc
OBJDIR := objdir
TARGET := main

#Compile w/flags, addmore?
CCC := g++
#CCFLAGS := -std=c++17 -g -Wall -Wextra -pedantic -Weffc++ -Wno-deprecated-declarations -I$(IDIR) -I$(SFML_ROOT)/include
#LDFLAGS := -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
CCFLAGS := -std=c++17 -g -Wall -Wextra -pedantic -Weffc++ -Wno-deprecated-declarations -I$(IDIR)
LDFLAGS := -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
#.cc filer
SRCEXT := cc


#source/objekt filer
SOURCES := $(shell find $(SRC) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRC)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

#Mål
$(TARGET): $(OBJECTS)
	@echo "Linking..."; $(CCC) $(CCFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Kompilera varje .cc-fil till .o
$(OBJDIR)/%.o: $(SRC)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."; $(CCC) $(CCFLAGS) -c $< -o $@

# Rensa
.PHONY: clean
clean:
	@rm -rf $(OBJDIR) *.gch core $(TARGET)

# Kör spelet
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Kolla minnesanvändning
.PHONY: valgrind
valgrind: $(TARGET)
#valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) 
	valgrind --leak-check=full --errors-for-leak-kinds=definite --show-leak-kinds=definite --quiet ./main
