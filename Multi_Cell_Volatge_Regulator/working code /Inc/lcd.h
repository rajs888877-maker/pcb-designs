/*
 * lcd.h
 *
 *  Created on: Feb 6, 2026
 *      Author: raj43
 */

#ifndef LCD_H_
#define LCD_H_

void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_clear();
void lcd_put_cur(int row, int col);
void lcd_init(void);
void lcd_send_str(char *str);





#endif /* LCD_H_ */
