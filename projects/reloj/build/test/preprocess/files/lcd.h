

typedef enum lcd_registro_e {

   LCD_CMD_REG = 0,

   LCD_DATA_REG = 1,

} lcd_registro_t;

void lcdEscribirDatos(lcd_registro_t command, uint8_t data);









void lcdInicializar(void);













void lcdCursor(uint8_t row, uint8_t col);





void lcdBorrar(void);











void lcdEscribirCadena(const char * text);
