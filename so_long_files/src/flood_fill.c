/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:54:36 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/27 17:54:38 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define MAX 10

void floodFill(int arr[MAX][MAX], int x, int y, int prevC, int newC) {
    if (x < 0 || x >= MAX || y < 0 || y >= MAX)
        return;
    if (arr[x][y] != prevC)
        return;
    arr[x][y] = newC;
    floodFill(arr, x+1, y, prevC, newC);
    floodFill(arr, x-1, y, prevC, newC);
    floodFill(arr, x, y+1, prevC, newC);
    floodFill(arr, x, y-1, prevC, newC);
}

int main() {
    int arr[MAX][MAX] = {{1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1, 0, 0},
                         {1, 0, 0, 1, 1, 0, 1, 1},
                         {1, 2, 2, 2, 2, 0, 1, 0},
                         {1, 1, 1, 2, 2, 0, 1, 0},
                         {1, 1, 1, 2, 2, 2, 2, 0},
                         {1, 1, 1, 1, 1, 2, 1, 1},
                         {1, 1, 1, 1, 1, 2, 2, 1},
                        };
    int x = 4, y = 4, newC = 3;
    floodFill(arr, x, y, arr[x][y], newC);

    printf("Updated screen \n");
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
