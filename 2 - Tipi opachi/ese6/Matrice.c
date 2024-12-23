/*  TE 02/2022
    ES.3 Tipi opachi
*/
#include "Matrice.h"
#include <stdio.h>
#include <stdlib.h>

struct matrice
{
    int **v_col;
    int dim;
};
m *costruttore(int n)
{
    m *mat = (m *)malloc(sizeof(m));

    mat->dim = n;
    mat->v_col = (int **)malloc(sizeof(int *) * mat->dim);

    for (int i = 0; i < mat->dim; i++)
    {
        mat->v_col[i] = (int *)malloc(sizeof(int) * mat->dim);
        for (int j = 0; j < mat->dim; j++)
        {
            mat->v_col[i][j] = 0;
        }
    }
    return mat;
}
char *toString(m *mat)
{
    char *res = (char *)malloc(sizeof(char) * (2 * mat->dim + 1) * mat->dim + 3);
    res[0] = '[';
    int c_s = 1;
    for (int j = 0; j < mat->dim; j++)
    {
        res[c_s++] = '[';
        for (int i = 0; i < mat->dim; i++)
        {
            res[c_s++] = (char)(mat->v_col[j][i] + '0');
            res[c_s++] = ',';
        }
        res[c_s - 1] = ']';
    }
    res[c_s] = ']';
    res[c_s + 1] = '\0';
    return res;
}
void set(m *matrice, int num, int r, int c)
{
    if (r <= matrice->dim && c <= matrice->dim)
        matrice->v_col[r - 1][c - 1] = num;
}
m *somma(m *m1, m *m2)
{
    int dim = m1->dim < m2->dim ? m2->dim : m1->dim;
    m *m_res = costruttore(dim);

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            // Controlla se l'elemento corrente è valido per entrambe le matrici
            if (i < m1->dim && j < m1->dim && i < m2->dim && j < m2->dim)
            {
                m_res->v_col[i][j] = m1->v_col[i][j] + m2->v_col[i][j];
            }
            // Se l'elemento è valido solo per una delle due matrici, assegna il valore dell'altra
            else if (i < m1->dim && j < m1->dim)
            {
                m_res->v_col[i][j] = m1->v_col[i][j];
            }
            else if (i < m2->dim && j < m2->dim)
            {
                m_res->v_col[i][j] = m2->v_col[i][j];
            }
        }
    }
    return m_res;
}
void cancella(m *mat)
{
    // ATTENZIONE: devi fare la free delle righe e delle colonne!
    for (int i = 0; i < mat->dim; i++)
        free(mat->v_col[i]);
    free(mat->v_col);
    free(mat);
}