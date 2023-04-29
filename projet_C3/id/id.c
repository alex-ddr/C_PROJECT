unsigned int global_id = 0;
unsigned int get_next_id()
{
    return global_id+= 1;

}
unsigned int get_previous_id()
{
    return global_id-= 1;

}