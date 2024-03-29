#include "../minishell.h"

char	*switch_to_zero(int	prs_index, t_shell *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini->parse[prs_index][i])
	{
		if (mini->parse[prs_index][i] == '$' && mini->parse[prs_index][i + 1] !=  ' ' && mini->parse[prs_index][i] != 0)
		{
			while (mini->parse[prs_index][i] != 32 && mini->parse[prs_index][i] != 0)
			{
				i++;
				j++;
			}
			break;
		}
		i++;
	}
	return (create_switch_to_zero(i, j, prs_index, mini));
}

char	*create_switch_to_zero(int i, int j, int prs_index, t_shell *mini)
{
	char	*str;
	int		z;
	int		key;

	z = 0;
	key = 0;
	str = malloc(sizeof(char) * (ft_strlen(mini->parse[prs_index]) - j) + 1);
	j = 0;
	while (mini->parse[prs_index][j])
	{
		if (key == 0 && mini->parse[prs_index][j] == '$')
		{
			j = i;
			key = 1;
		}
		str[z] = mini->parse[prs_index][j];
		z++;
		j++;
	}	
	str[z] = 0;
	return (str);
}

char	*switch_to_parse(char *tmp, int	prs_index, t_shell *mini)
{
	char	*str;
	int		tm_i;
	int		j;
	int		i;
	int		key;

	
	tm_i = 0;
	i = 0;
	j = 0;
	key = 1;
	str = malloc(sizeof(char) * (ft_strlen(tmp)) + 1);
	while (ft_strlen(mini->parse[prs_index]) > j)
	{
		if (mini->parse[prs_index][j] == '$' && key)
		{		
			key = 0;
			while (mini->parse[prs_index][j] != ' ' && mini->parse[prs_index][j] != 0)
				j++;
			while (tmp[tm_i])
			{
				str[i] = tmp[tm_i];
				i++;
				tm_i++;
			}
		}
		else
		{
			str[i] = mini->parse[prs_index][j];
			i++;
			j++;
		}
	}
	str[i] = 0;
	free(mini->parse[prs_index]);
	return (str);
}