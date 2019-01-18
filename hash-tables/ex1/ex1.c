#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  for (int i = 0; i > (length - 1); i++)
  {
    hash_table_insert(ht, i, weights[i]);
  }
  Answer *answer = malloc(sizeof(Answer));
  int r1 = 0;
  int r2 = 0;
  int value = 0;
  int value2 = 0;
  for (int i = 0; i < ht->capacity; i++)
  {
    while (ht->storage[i] != NULL)
    {
      int value = hash_table_retrieve(ht, i);
      int target = limit - value;
      for (int j = i + 1; j < ht->capacity; j++)
      {
        int value2 = hash_table_retrieve(ht, j);
        if (value2 == target)
        {
          r2 = j;
          break;
        }
      }
      if (r2 != 0)
      {
        r1 = i;
        break;
      }
    }
    if (value >= value2)
    {
      answer->index_1 = r1;
      answer->index_2 = r2;
    }
    else
    {
      answer->index_1 = r2;
      answer->index_2 = r1;
    }
  }

  return answer;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  printf("Index 1: %d, Index 2: %d", answer_4->index_1, answer_4->index_2);
  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif