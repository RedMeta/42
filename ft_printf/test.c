#include <stdio.h>
#include <stdlib.h>

struct s_list
{
	char 			*content;
	struct s_list	*next;
};

typedef struct s_list list;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[j] && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize - j > 0)
		dst[j] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*new;
	size_t		size;
	size_t		s_size;

	size = 0;
	while (s1[size])
		++size;
	if (!(new = (void *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(new, s1, (s_size = ft_strlen(s1)) + 1);
	new[s_size] = '\0';
	return (new);
}

list	*ft_lstnew(void *content)
{
	list *list;

	list = (list *)malloc(sizeof(list));
	if (list)
	{
		list->content = content;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}

void	ft_lstadd_back(list **lst, list *new)
{
	list		*current;

	if (lst && *lst)
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else if (lst)
		*lst = new;
}

int main()
{



}