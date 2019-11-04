.PHONY: clean All

All:
	@echo ----------Building project:[ tt - Debug ]----------
	@"$(MAKE)" -f "tt.mk"
clean:
	@echo ----------Cleaning project:[ tt - Debug ]----------
	@"$(MAKE)" -f "tt.mk" clean
