#ifndef DWM_COLORIZATION_PARAMETERS_PROC
#define DWM_COLORIZATION_PARAMETERS_PROC

typedef void(*DwmSetColorizationParametersProc) (DwmColorizationParameters *);
typedef void(*DwmGetColorizationParametersProc) (DwmColorizationParameters *);

#endif

void singleTransition(Color, Color, int, int, DwmSetColorizationParametersProc);

