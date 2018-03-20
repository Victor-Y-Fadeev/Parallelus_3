using ZedGraph;

namespace Visualization
{
    internal class Result
    {
        public Result(PointPairList pounts, bool isToRight)
        {
            Pounts = pounts;
            IsToRight = isToRight;
        }
        
        public PointPairList Pounts { get; set; }
        public bool IsToRight { get; set; }
    }
}