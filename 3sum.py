class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sz = len(nums)
        if sz < 3:
            return []

        nums.sort()
        rslt: List[List[int]] = []
        # print(nums)
        pos = []
        findPositivePosition(nums, 0, sz - 1, pos)
        origin_pos = pos[0]
        # print(origin_pos)

        if origin_pos == 0:
            return []

        for i in range(1, sz - 1):
            if i <= origin_pos:
                lf = i-1
                rt = max(origin_pos, i + 1)
            else:
                lf = min(origin_pos, i-1)
                rt = i + 1
            # print("lf:"+str(lf)+" mid:" +
            #       str(i) + " rt:" + str(rt))
            while lf >= 0 and rt <= sz - 1:

                val_lf = nums[lf]
                val_mid = nums[i]
                val_rt = nums[rt]
                # print("lf:"+str(lf)+"("+str(val_lf)+")" +
                #       " mid:"+str(i) + "("+str(val_mid)+")" + " rt:" + str(rt) + "("+str(val_rt)+")")

                if val_lf + val_mid + val_rt == 0:
                    answer = [val_lf, val_mid, val_rt]
                    if HaveDuplicate(rslt, answer) == False:
                        rslt.append(answer)

                if lf == 0 and abs(val_lf+val_mid) < abs(val_rt):
                    break
                elif rt == sz-1 and abs(val_rt+val_mid) < abs(val_lf):
                    break
                elif abs(val_lf + val_mid) <= abs(val_rt) or val_lf > 0:
                    lf -= 1
                else:
                    rt += 1

        return rslt


def findPositivePosition(nums: List[int], bgn: int, end: int, origin_pos: List[int]):
    if(end-bgn > 1):
        mid = int((bgn + end) / 2)
        if (nums[mid] < 0):
            findPositivePosition(nums, mid, end, origin_pos)
        else:
            findPositivePosition(nums, bgn, mid, origin_pos)
    else:
        origin_pos.append(end)


def HaveDuplicate(existing_answers: List[List[int]], answer: List[int]) -> bool:
    exist = False
    for i in existing_answers:
        dif = False
        for j in range(0, 3):
            if answer[j] != i[j]:
                dif = True
        if dif == False:
            return True
    return False
