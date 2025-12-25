# Makefile for clibstruct

# Variables
DOXYGEN = doxygen
DOXYFILE = Doxyfile

# Phony targets
.PHONY: all docs clean

# Default target
all: docs

# Generate documentation
docs:
	$(DOXYGEN) $(DOXYFILE)

# Clean generated documentation
clean:
	rm -rf html latex
