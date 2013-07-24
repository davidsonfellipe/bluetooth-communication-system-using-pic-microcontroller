/**
 * Define o nome com o quais outros dispositivos enxergarão o dispositivo
 * @package bt_pic_api
 */
void bt_localname_set(char *novoNome)
{
	char buffer[37];
	int n;
	n=sprintf (buffer, "AT+ZV DefaultLocalName %s", novoNome);
	printf("%s", buffer);
	putc(0x0d); //CR
	putc(0x0a); //new line
}
/**
* inicia conexão com outro dispositivo
* @package bt_pic_api
*/
void bt_connect(char *bd_address, char *senha)
{
	char buffer[40];
	int n;
	n=sprintf (buffer, " AT+ZV Bond %s %s", bd_address, senha);
	printf("%s", buffer);
	putc(0x0d); //CR
	putc(0x0a); //new line
}
/**
* Envia uma string a um dispositivo
* @package bt_pic_api
*/
void bt_send_string(char *string)
{
	printf("%s", string);
}
/**
* Aplica um reset no dispositivo
* @package bt_pic_api
*/
void bt_reset()
{
	printf("AT+ZV Reset");
	putc(0x0d); //CR
    putc(0x0a); //new line	 
}