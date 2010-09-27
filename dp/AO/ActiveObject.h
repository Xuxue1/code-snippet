
class CActiveObject
{
public:
    void SetPriority();
    bool IsActive();
    void Cancel();
private:
    virtual void DoCancel() = 0;
};
