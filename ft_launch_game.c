#include "./includes/cub.h"

int	ft_close_win(t_info *info)
{
	mlx_destroy_window(info->swin.mlx, info->swin.win);
	ft_free_all(info);
	exit(EXIT_SUCCESS);
	return (1);
}

int ft_key_press(int key, t_info *info)
{
	printf("\nkey: %d\n", key);
	if(key == ESC)
		ft_close_win(info);
//	if (key == W)
//		ft_move_forward();
//	if (key == S)
//		ft_move_down();
//	if (key == A)
//		ft_move_left();
//	if (key == D)
//		ft_move_right();
//	if (key == LEFT)
//		ft_turn_left();
//	if (key == RIGHT)
//		ft_turn_rigth();
	return (1);
}

/**
 * чтобы запустить игру нужно:
 * 		1)заполненные + проверенные на валидность параметры
 * 		2)проверенная на валидность карта
 *
 */
void ft_init_img(t_info *info)
{
	info->swin.img = mlx_new_image(info->swin.mlx,info->res_y, info->res_x);
	info->swin.addr = mlx_get_data_addr(info->swin.img, &info->swin.bpp, &info->swin.line_l, &info->swin.en);
}
void ft_frame_render(t_info *info)
{
	ft_init_img(info);
//	pixel_put(info->swin.win,5,5,0xFFFFFF);
	mlx_put_image_to_window(info->swin.mlx, info->swin.win, info->swin.img,0,0);
}


void ft_launch_game(t_info *info)
{
	if (!(info->swin.mlx = mlx_init()))
		ft_error("Can't init mlx\n", info);
	info->swin.win = mlx_new_window(info->swin.mlx, info->res_x, info->res_y, info->filename);
	ft_frame_render(info);
	mlx_hook(info->swin.win, 02, 1L << 0,ft_key_press,info);
	mlx_hook(info->swin.win,17,1L << 17, ft_close_win, info);
	mlx_loop(info->swin.mlx);


}
