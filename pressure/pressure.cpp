


void pressure::base()
{
	int i,j,k, rep;

	for(rep = 0; rep < numReps; rep++)
	{
		
		for(i = ibegin; i < iend; i++) {
			PRESSURE_BODY1;
		}
		for(i = ibegin; i < iend; i++) {
			PRESSURE_BODY2;
		}
	}
}

void pressure::omp_basic() {

	int i,j,k, rep;

	for(rep = 0; rep < numReps; rep++)
	{
		#pragma omp parallel for
		for(i = ibegin; i < iend; i++) {
			PRESSURE_BODY1;
		}
		
		#pragma omp parallel for
		for(i = ibegin; i < iend; i++) {
			PRESSURE_BODY2;
		}
	}
}

	
	
