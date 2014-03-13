#ifndef DWM_COLORIZATION_PARAMETERS_PROC
#define DWM_COLORIZATION_PARAMETERS_PROC

/*
typedef HRESULT(WINAPI*DwmSetColorizationParametersProc) (DwmColorizationParameters *, UINT);
typedef HRESULT(WINAPI*DwmGetColorizationParametersProc) (DwmColorizationParameters *);
*/

HRESULT(WINAPI *DwmSetColorizationParameters) (DwmColorizationParameters *color, UINT unknown);
HRESULT(WINAPI *DwmGetColorizationParameters) (DwmColorizationParameters *color);


#endif

//void singleTransition(Color, Color, int, int, DwmSetColorizationParametersProc);
