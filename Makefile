for_example:
	@echo Running loop without OpenMP
	@echo ----------------------------------------\|
	@outputs/for_example_no_openmp
	@echo ----------------------------------------\|
	@echo Running loop with OpenMP parallelization
	@echo ----------------------------------------\|
	@outputs/for_example_with_openmp
	@echo ----------------------------------------\|

consistency:
	@echo Running without OpenMP flush consistency
	@echo ----------------------------------------\|
	@outputs/no_flush_example
	@echo ----------------------------------------\|
	@echo Running with OpenMP flush consistency
	@echo ----------------------------------------\|
	@outputs/flush_example_with_openmp
	@echo ----------------------------------------\|
