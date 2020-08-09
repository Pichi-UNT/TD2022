/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_lcd.h"

static const char* CMockString_col = "col";
static const char* CMockString_command = "command";
static const char* CMockString_data = "data";
static const char* CMockString_lcdBorrar = "lcdBorrar";
static const char* CMockString_lcdCursor = "lcdCursor";
static const char* CMockString_lcdEscribirCadena = "lcdEscribirCadena";
static const char* CMockString_lcdEscribirDatos = "lcdEscribirDatos";
static const char* CMockString_lcdInicializar = "lcdInicializar";
static const char* CMockString_row = "row";
static const char* CMockString_text = "text";

typedef struct _CMOCK_lcdEscribirDatos_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  lcd_registro_t Expected_command;
  uint8_t Expected_data;

} CMOCK_lcdEscribirDatos_CALL_INSTANCE;

typedef struct _CMOCK_lcdInicializar_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_lcdInicializar_CALL_INSTANCE;

typedef struct _CMOCK_lcdCursor_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint8_t Expected_row;
  uint8_t Expected_col;

} CMOCK_lcdCursor_CALL_INSTANCE;

typedef struct _CMOCK_lcdBorrar_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_lcdBorrar_CALL_INSTANCE;

typedef struct _CMOCK_lcdEscribirCadena_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  const char* Expected_text;

} CMOCK_lcdEscribirCadena_CALL_INSTANCE;

static struct mock_lcdInstance
{
  char lcdEscribirDatos_IgnoreBool;
  char lcdEscribirDatos_CallbackBool;
  CMOCK_lcdEscribirDatos_CALLBACK lcdEscribirDatos_CallbackFunctionPointer;
  int lcdEscribirDatos_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE lcdEscribirDatos_CallInstance;
  char lcdInicializar_IgnoreBool;
  char lcdInicializar_CallbackBool;
  CMOCK_lcdInicializar_CALLBACK lcdInicializar_CallbackFunctionPointer;
  int lcdInicializar_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE lcdInicializar_CallInstance;
  char lcdCursor_IgnoreBool;
  char lcdCursor_CallbackBool;
  CMOCK_lcdCursor_CALLBACK lcdCursor_CallbackFunctionPointer;
  int lcdCursor_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE lcdCursor_CallInstance;
  char lcdBorrar_IgnoreBool;
  char lcdBorrar_CallbackBool;
  CMOCK_lcdBorrar_CALLBACK lcdBorrar_CallbackFunctionPointer;
  int lcdBorrar_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE lcdBorrar_CallInstance;
  char lcdEscribirCadena_IgnoreBool;
  char lcdEscribirCadena_CallbackBool;
  CMOCK_lcdEscribirCadena_CALLBACK lcdEscribirCadena_CallbackFunctionPointer;
  int lcdEscribirCadena_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE lcdEscribirCadena_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_lcd_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.lcdEscribirDatos_CallInstance;
  if (Mock.lcdEscribirDatos_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_lcdEscribirDatos);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.lcdEscribirDatos_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.lcdInicializar_CallInstance;
  if (Mock.lcdInicializar_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_lcdInicializar);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.lcdInicializar_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.lcdCursor_CallInstance;
  if (Mock.lcdCursor_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_lcdCursor);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.lcdCursor_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.lcdBorrar_CallInstance;
  if (Mock.lcdBorrar_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_lcdBorrar);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.lcdBorrar_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.lcdEscribirCadena_CallInstance;
  if (Mock.lcdEscribirCadena_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_lcdEscribirCadena);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.lcdEscribirCadena_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_lcd_Init(void)
{
  mock_lcd_Destroy();
}

void mock_lcd_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void lcdEscribirDatos(lcd_registro_t command, uint8_t data)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_lcdEscribirDatos_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcdEscribirDatos);
  cmock_call_instance = (CMOCK_lcdEscribirDatos_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcdEscribirDatos_CallInstance);
  Mock.lcdEscribirDatos_CallInstance = CMock_Guts_MemNext(Mock.lcdEscribirDatos_CallInstance);
  if (Mock.lcdEscribirDatos_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.lcdEscribirDatos_CallbackBool &&
      Mock.lcdEscribirDatos_CallbackFunctionPointer != NULL)
  {
    Mock.lcdEscribirDatos_CallbackFunctionPointer(command, data, Mock.lcdEscribirDatos_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_lcdEscribirDatos,CMockString_command);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_command), (void*)(&command), sizeof(lcd_registro_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcdEscribirDatos,CMockString_data);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_data, data, cmock_line, CMockStringMismatch);
  }
  if (Mock.lcdEscribirDatos_CallbackFunctionPointer != NULL)
  {
    Mock.lcdEscribirDatos_CallbackFunctionPointer(command, data, Mock.lcdEscribirDatos_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcdEscribirDatos(CMOCK_lcdEscribirDatos_CALL_INSTANCE* cmock_call_instance, lcd_registro_t command, uint8_t data)
{
  memcpy((void*)(&cmock_call_instance->Expected_command), (void*)(&command),
         sizeof(lcd_registro_t[sizeof(command) == sizeof(lcd_registro_t) ? 1 : -1])); /* add lcd_registro_t to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_data = data;
}

void lcdEscribirDatos_CMockIgnore(void)
{
  Mock.lcdEscribirDatos_IgnoreBool = (char)1;
}

void lcdEscribirDatos_CMockStopIgnore(void)
{
  Mock.lcdEscribirDatos_IgnoreBool = (char)0;
}

void lcdEscribirDatos_CMockExpect(UNITY_LINE_TYPE cmock_line, lcd_registro_t command, uint8_t data)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcdEscribirDatos_CALL_INSTANCE));
  CMOCK_lcdEscribirDatos_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcdEscribirDatos_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcdEscribirDatos_CallInstance = CMock_Guts_MemChain(Mock.lcdEscribirDatos_CallInstance, cmock_guts_index);
  Mock.lcdEscribirDatos_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_lcdEscribirDatos(cmock_call_instance, command, data);
}

void lcdEscribirDatos_AddCallback(CMOCK_lcdEscribirDatos_CALLBACK Callback)
{
  Mock.lcdEscribirDatos_IgnoreBool = (char)0;
  Mock.lcdEscribirDatos_CallbackBool = (char)1;
  Mock.lcdEscribirDatos_CallbackFunctionPointer = Callback;
}

void lcdEscribirDatos_Stub(CMOCK_lcdEscribirDatos_CALLBACK Callback)
{
  Mock.lcdEscribirDatos_IgnoreBool = (char)0;
  Mock.lcdEscribirDatos_CallbackBool = (char)0;
  Mock.lcdEscribirDatos_CallbackFunctionPointer = Callback;
}

void lcdInicializar(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_lcdInicializar_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcdInicializar);
  cmock_call_instance = (CMOCK_lcdInicializar_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcdInicializar_CallInstance);
  Mock.lcdInicializar_CallInstance = CMock_Guts_MemNext(Mock.lcdInicializar_CallInstance);
  if (Mock.lcdInicializar_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.lcdInicializar_CallbackBool &&
      Mock.lcdInicializar_CallbackFunctionPointer != NULL)
  {
    Mock.lcdInicializar_CallbackFunctionPointer(Mock.lcdInicializar_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.lcdInicializar_CallbackFunctionPointer != NULL)
  {
    Mock.lcdInicializar_CallbackFunctionPointer(Mock.lcdInicializar_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void lcdInicializar_CMockIgnore(void)
{
  Mock.lcdInicializar_IgnoreBool = (char)1;
}

void lcdInicializar_CMockStopIgnore(void)
{
  Mock.lcdInicializar_IgnoreBool = (char)0;
}

void lcdInicializar_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcdInicializar_CALL_INSTANCE));
  CMOCK_lcdInicializar_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcdInicializar_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcdInicializar_CallInstance = CMock_Guts_MemChain(Mock.lcdInicializar_CallInstance, cmock_guts_index);
  Mock.lcdInicializar_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void lcdInicializar_AddCallback(CMOCK_lcdInicializar_CALLBACK Callback)
{
  Mock.lcdInicializar_IgnoreBool = (char)0;
  Mock.lcdInicializar_CallbackBool = (char)1;
  Mock.lcdInicializar_CallbackFunctionPointer = Callback;
}

void lcdInicializar_Stub(CMOCK_lcdInicializar_CALLBACK Callback)
{
  Mock.lcdInicializar_IgnoreBool = (char)0;
  Mock.lcdInicializar_CallbackBool = (char)0;
  Mock.lcdInicializar_CallbackFunctionPointer = Callback;
}

void lcdCursor(uint8_t row, uint8_t col)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_lcdCursor_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcdCursor);
  cmock_call_instance = (CMOCK_lcdCursor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcdCursor_CallInstance);
  Mock.lcdCursor_CallInstance = CMock_Guts_MemNext(Mock.lcdCursor_CallInstance);
  if (Mock.lcdCursor_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.lcdCursor_CallbackBool &&
      Mock.lcdCursor_CallbackFunctionPointer != NULL)
  {
    Mock.lcdCursor_CallbackFunctionPointer(row, col, Mock.lcdCursor_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_lcdCursor,CMockString_row);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_row, row, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_lcdCursor,CMockString_col);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_col, col, cmock_line, CMockStringMismatch);
  }
  if (Mock.lcdCursor_CallbackFunctionPointer != NULL)
  {
    Mock.lcdCursor_CallbackFunctionPointer(row, col, Mock.lcdCursor_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcdCursor(CMOCK_lcdCursor_CALL_INSTANCE* cmock_call_instance, uint8_t row, uint8_t col)
{
  cmock_call_instance->Expected_row = row;
  cmock_call_instance->Expected_col = col;
}

void lcdCursor_CMockIgnore(void)
{
  Mock.lcdCursor_IgnoreBool = (char)1;
}

void lcdCursor_CMockStopIgnore(void)
{
  Mock.lcdCursor_IgnoreBool = (char)0;
}

void lcdCursor_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t row, uint8_t col)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcdCursor_CALL_INSTANCE));
  CMOCK_lcdCursor_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcdCursor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcdCursor_CallInstance = CMock_Guts_MemChain(Mock.lcdCursor_CallInstance, cmock_guts_index);
  Mock.lcdCursor_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_lcdCursor(cmock_call_instance, row, col);
}

void lcdCursor_AddCallback(CMOCK_lcdCursor_CALLBACK Callback)
{
  Mock.lcdCursor_IgnoreBool = (char)0;
  Mock.lcdCursor_CallbackBool = (char)1;
  Mock.lcdCursor_CallbackFunctionPointer = Callback;
}

void lcdCursor_Stub(CMOCK_lcdCursor_CALLBACK Callback)
{
  Mock.lcdCursor_IgnoreBool = (char)0;
  Mock.lcdCursor_CallbackBool = (char)0;
  Mock.lcdCursor_CallbackFunctionPointer = Callback;
}

void lcdBorrar(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_lcdBorrar_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcdBorrar);
  cmock_call_instance = (CMOCK_lcdBorrar_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcdBorrar_CallInstance);
  Mock.lcdBorrar_CallInstance = CMock_Guts_MemNext(Mock.lcdBorrar_CallInstance);
  if (Mock.lcdBorrar_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.lcdBorrar_CallbackBool &&
      Mock.lcdBorrar_CallbackFunctionPointer != NULL)
  {
    Mock.lcdBorrar_CallbackFunctionPointer(Mock.lcdBorrar_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.lcdBorrar_CallbackFunctionPointer != NULL)
  {
    Mock.lcdBorrar_CallbackFunctionPointer(Mock.lcdBorrar_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void lcdBorrar_CMockIgnore(void)
{
  Mock.lcdBorrar_IgnoreBool = (char)1;
}

void lcdBorrar_CMockStopIgnore(void)
{
  Mock.lcdBorrar_IgnoreBool = (char)0;
}

void lcdBorrar_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcdBorrar_CALL_INSTANCE));
  CMOCK_lcdBorrar_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcdBorrar_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcdBorrar_CallInstance = CMock_Guts_MemChain(Mock.lcdBorrar_CallInstance, cmock_guts_index);
  Mock.lcdBorrar_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void lcdBorrar_AddCallback(CMOCK_lcdBorrar_CALLBACK Callback)
{
  Mock.lcdBorrar_IgnoreBool = (char)0;
  Mock.lcdBorrar_CallbackBool = (char)1;
  Mock.lcdBorrar_CallbackFunctionPointer = Callback;
}

void lcdBorrar_Stub(CMOCK_lcdBorrar_CALLBACK Callback)
{
  Mock.lcdBorrar_IgnoreBool = (char)0;
  Mock.lcdBorrar_CallbackBool = (char)0;
  Mock.lcdBorrar_CallbackFunctionPointer = Callback;
}

void lcdEscribirCadena(const char* text)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_lcdEscribirCadena_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_lcdEscribirCadena);
  cmock_call_instance = (CMOCK_lcdEscribirCadena_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.lcdEscribirCadena_CallInstance);
  Mock.lcdEscribirCadena_CallInstance = CMock_Guts_MemNext(Mock.lcdEscribirCadena_CallInstance);
  if (Mock.lcdEscribirCadena_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.lcdEscribirCadena_CallbackBool &&
      Mock.lcdEscribirCadena_CallbackFunctionPointer != NULL)
  {
    Mock.lcdEscribirCadena_CallbackFunctionPointer(text, Mock.lcdEscribirCadena_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_lcdEscribirCadena,CMockString_text);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_text, text, cmock_line, CMockStringMismatch);
  }
  if (Mock.lcdEscribirCadena_CallbackFunctionPointer != NULL)
  {
    Mock.lcdEscribirCadena_CallbackFunctionPointer(text, Mock.lcdEscribirCadena_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_lcdEscribirCadena(CMOCK_lcdEscribirCadena_CALL_INSTANCE* cmock_call_instance, const char* text)
{
  cmock_call_instance->Expected_text = text;
}

void lcdEscribirCadena_CMockIgnore(void)
{
  Mock.lcdEscribirCadena_IgnoreBool = (char)1;
}

void lcdEscribirCadena_CMockStopIgnore(void)
{
  Mock.lcdEscribirCadena_IgnoreBool = (char)0;
}

void lcdEscribirCadena_CMockExpect(UNITY_LINE_TYPE cmock_line, const char* text)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_lcdEscribirCadena_CALL_INSTANCE));
  CMOCK_lcdEscribirCadena_CALL_INSTANCE* cmock_call_instance = (CMOCK_lcdEscribirCadena_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.lcdEscribirCadena_CallInstance = CMock_Guts_MemChain(Mock.lcdEscribirCadena_CallInstance, cmock_guts_index);
  Mock.lcdEscribirCadena_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_lcdEscribirCadena(cmock_call_instance, text);
}

void lcdEscribirCadena_AddCallback(CMOCK_lcdEscribirCadena_CALLBACK Callback)
{
  Mock.lcdEscribirCadena_IgnoreBool = (char)0;
  Mock.lcdEscribirCadena_CallbackBool = (char)1;
  Mock.lcdEscribirCadena_CallbackFunctionPointer = Callback;
}

void lcdEscribirCadena_Stub(CMOCK_lcdEscribirCadena_CALLBACK Callback)
{
  Mock.lcdEscribirCadena_IgnoreBool = (char)0;
  Mock.lcdEscribirCadena_CallbackBool = (char)0;
  Mock.lcdEscribirCadena_CallbackFunctionPointer = Callback;
}

