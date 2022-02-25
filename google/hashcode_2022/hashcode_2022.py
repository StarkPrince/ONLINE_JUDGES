from tkinter import E


index_file = int(input())

files = [
    ["a_an_example.in.txt", "a_an_example.out.txt"],
    ["b_better_start_small.in.txt", "b_better_start_small.out.txt"],
    ["c_collaboration.in.txt", "c_collaboration.out.txt"],
    ["d_dense_schedule.in.txt", "d_dense_schedule.out.txt"],
    ["e_exceptional_skills.in.txt", "e_exceptional_skills.out.txt"],
    ["f_find_great_mentors.in.txt", "f_find_great_mentors.out.txt"],
]

person_skills = {}
projects = {}
another_project = []
skill_persons = {}

with open("./input_data/"+files[index_file][0], 'r') as f:
    no_of_contributors, no_of_projects = f.readline().split(' ')

    for contributor_index in range(int(no_of_contributors)):
        contributor, no_of_skills = f.readline().split(' ')
        person_skills[contributor] = {"on_day": 0}
        for skills in range(int(no_of_skills)):
            skill, skill_level = f.readline().split(' ')
            person_skills[contributor][skill] = int(skill_level)
            if skill not in skill_persons:
                skill_persons[skill] = {}
            skill_persons[skill][contributor] = int(skill_level)

    for project_index in range(int(no_of_projects)):
        project_name, days_to_comp, score, best_before, roles = f.readline().strip().split(' ')
        projects[project_name] = {}
        projects[project_name]['days_to_comp'] = int(days_to_comp)
        projects[project_name]['score'] = int(score)
        projects[project_name]['best_before'] = int(best_before)
        projects[project_name]['roles'] = {}

        temp = []

        for role in range(int(roles)):
            project_role, level_req = f.readline().strip().split(' ')
            temp.append([project_role, int(level_req)])
            if project_role not in projects[project_name]['roles']:
                projects[project_name]['roles'][project_role] = []
            projects[project_name]['roles'][project_role].append(
                int(level_req))

        another_project.append(temp)

"""
assigned = {}
with open("output_data/"+files[index_file][1], 'r') as f:
    no_of_projects = f.readline().strip()
    for project_index in range(int(no_of_projects)):
        project_name = f.readline().strip()
        assingnies = f.readline().strip().split(' ')
        assigned[project_name] = assingnies


def simulator(assigned):
    days_passed = -1
    final_score = 0
    for project, assignies in assigned.items():
        day_to_comp = projects[project]['days_to_comp']
        score = projects[project]['score']
        best_before = projects[project]['best_before']
        days_passed += day_to_comp

        group_free_day = -1
        for assignie in assignies:
            group_free_day = max(
                group_free_day, person_skills[assignie]['on_day'])

        if group_free_day + day_to_comp <= best_before:
            final_score += score
        else:
            final_score += max(0, score - (group_free_day +
                                           day_to_comp - best_before))

        for assignie in assignies:
            person_skills[assignie]['on_day'] = group_free_day + day_to_comp
    return final_score


# for person, skills in person_skills.items():
#     print(person, skills)
# print()

# for project_name, project_details in projects.items():
#     print(project_name, project_details)
# print()

# print(assigned)
print(simulator(assigned))

"""

sorted_projects = sorted(
    projects.items(), key=lambda x: x[1]['score']/x[1]['best_before'], reverse=True)


def form_a_team(project_details, skill_persons, person_skills):
    ans = []
    ctr = 0
    for project, details in project_details:
        temp = []
        choose_from = {}
        roles = details['roles']
        for role, levels_req in roles.items():
            levels_req = sorted(levels_req, reverse=True)
            role_specific_persons = skill_persons[role].keys()

            role_specific_persons = sorted(
                role_specific_persons, key=lambda x: person_skills[x][role]/(person_skills[x]['on_day']+1), reverse=True)

            choose_from[role] = role_specific_persons

        projs = another_project[ctr]

        diff_index = {}
        for proj_name, proj_lev in projs:
            if proj_name not in diff_index:
                diff_index[proj_name] = 0
            while(proj_name in choose_from and diff_index[proj_name] < len(choose_from[proj_name]) and person_skills[choose_from[proj_name][diff_index[proj_name]]][proj_name] < proj_lev):
                diff_index[proj_name] += 1
            if proj_name not in choose_from or diff_index[proj_name] == len(choose_from[proj_name]):
                break
            temp.append(choose_from[proj_name][diff_index[proj_name]])
            diff_index[proj_name] += 1
        if len(temp) == len(roles):
            ans.append([project, temp])
        ctr += 1
    return ans


ans = form_a_team(sorted_projects, skill_persons, person_skills)
# print(ans)
with open("output_data/"+files[index_file][1], 'w') as f:
    f.write(str(len(ans)) + "\n")
    for project, assignees in ans:
        f.write(project + "\n" + " ".join(assignees) + "\n")
"""
