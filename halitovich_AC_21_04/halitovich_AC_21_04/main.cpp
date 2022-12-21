#include "template_utility.h"
#include "gtn_utility.h"

int main()
{
    int cmmnd = 1; // ����������, �������� ������� ������������ 
    GTN_data gtn_struct; // ����� ��������� �� �����
    string delimeter_screen = "*******************************************************************************";

    do { // ���� ��� ���������� ������ ������������
        cout << endl << delimeter_screen << endl;
        switch (cmmnd) { // ����� ����� � ������� ����
        case 0: {
            return(0);
        }
        case 1: {
            help();
            break;
        }
        case 2: { // �������� ��� �������
            show_object_pipe(gtn_struct.pipe_struct.mp_pipe);
            show_object_cs(gtn_struct.cs_struct.mp_cs);
            break;
        }
        case 3: { // �������� �����
            add_object_pipe(gtn_struct.pipe_struct);
            break;
        }
        case 4: { // �������������  �����
            interact(gtn_struct.pipe_struct.mp_pipe, edit_pipe);
            break;
        }
        case 5: { // ������� �����
            interact(gtn_struct.pipe_struct.mp_pipe, delete_pipe);
            break;
        }
        case 6: { // �������� ��
            add_object_cs(gtn_struct.cs_struct);
            break;
        }
        case 7: { // ������������� ��
            interact(gtn_struct.cs_struct.mp_cs, edit_cs);
            break;
        }
        case 8: { // ������� ��
            interact(gtn_struct.cs_struct.mp_cs, delete_cs);
            break;
        }
        case 9: { // ���������� � �������������� ���� �� �������
            filtering_pipe_repair(gtn_struct.pipe_struct.mp_pipe);
            break;
        }
        case 10: { // ���������� ���� �� ��������
            filtering_pipe_name(gtn_struct.pipe_struct.mp_pipe);
            break;
        }
        case 11: { // ���������� �� �� �������� ��������������� �����
            filtering_cs_workshops_on(gtn_struct.cs_struct.mp_cs);
            break;
        }
        case 12: { // ���������� �� �� ��������
            filtering_cs_name(gtn_struct.cs_struct.mp_cs);
            break;
        }
        case 13: {
            create_new_connection(gtn_struct.connect_struct, gtn_struct.pipe_struct, gtn_struct.cs_struct.mp_cs);
            break;
        }
        case 14: {
            show_all_connection(gtn_struct);
            break;
        }
        case 15: {
            component_of_graph(gtn_struct);
            break;
        }
        case 16: {
            topology_sort_by_dfs(gtn_struct);
            break;
        }
        case 17: {
            find_all_shortest_path(gtn_struct);
            break;
        }
        case 18: {
            find_max_flow(gtn_struct);
            break;
        }
        case 19: {
            save_data(gtn_struct);
            break;
        }
        case 20: {
            load_data(gtn_struct);
            break;
        }
        default: {
            break;
        }
        }
        cout << endl << delimeter_screen << endl;
        cout << "\n Main Menu >> ";
        cmmnd = checker(0, 20);
    } while (1);
    cout << " Good luck!\n\n\n";
}